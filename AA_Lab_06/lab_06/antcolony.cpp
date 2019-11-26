#include "antcolony.h"

pathInfo runColony(environment &env)
{
	pathInfo curBest;

	for (size_t i = 0; i < env.tMax; i++)
	{
		for (size_t j = 0; j < env.cities; j++)
		{
			pathInfo tmp =  runAnt(env, j);

			if (tmp.path.size() == env.cities && curBest.len == 0)
				curBest = tmp;
			if (tmp.path.size() == env.cities && curBest.len > tmp.len)
				curBest = tmp;
		}

		recalculateTau(env);
	}

	return curBest;
}

pathInfo runAnt(environment &env, size_t baseCity)
{
	pathInfo curPath;

	while (1)
	{
		std::vector<double> probs;
		double probsDivider = 0;
		if (!isInVector(curPath.path, baseCity))
			curPath.path.push_back(baseCity);
		else
			break;

		for (size_t i = 0; i < env.cities; i++)
		{
			if (env.map[baseCity][i] > 0 && !isInVector(curPath.path, i))
			{
				probsDivider += std::pow(env.tau[baseCity][i], env.alpha)*
								std::pow(std::pow(env.map[baseCity][i], -1), env.beta);
			}
		}

		for (size_t i = 0; i < env.cities; i++)
		{
			if (isInVector(curPath.path, i) || env.map[baseCity][i] <= 0)
				probs.push_back(0);
			else
				probs.push_back(std::pow(env.tau[baseCity][i], env.alpha)*
								std::pow(std::pow(env.map[baseCity][i], -1), env.beta)/
								probsDivider);
		}

		double probsSum = 0;
		for (auto it : probs)
			probsSum += it;

		if (probsSum < 0.1)
			break;

		double randVal = (double(rand()) / (RAND_MAX)) + 0.000001;

		probsSum = 0;
		for (size_t i = 0; i < env.cities; i++)
		{
			probsSum += probs[i];
			if (probsSum >= randVal && !isInVector(curPath.path, i))
			{
				curPath.len += env.map[baseCity][i];

				baseCity = i;
				break;
			}
		}
	}

	size_t curPathSize = curPath.path.size();
	if (curPathSize == env.cities)
	{
		curPath.len *= 2;
		double dTau = env.Q / curPath.len;
		for (size_t i = 0; i < curPathSize - 1; i++)
		{
			env.dTau[curPath.path[i]][curPath.path[i+1]] += dTau;
			env.dTau[curPath.path[i+1]][curPath.path[i]] += dTau;
		}
	}

	return curPath;
}

void recalculateTau(environment &env)
{
	for (size_t i = 0; i < env.cities; i++)
	{
		for (size_t j = 0; j < env.cities; j++)
		{
            env.tau[i][j] = env.tau[i][j]*(1 - env.ro) + env.dTau[i][j];
            env.dTau[i][j] = 0;
		}
	}
}



