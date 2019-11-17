#include <iostream>
#include <vector>
#include <recursive.h>
#include <antcolony.h>

int main()
{
	MtrInt mtr = getMatrix();

	for (auto it : mtr)
	{
		for (auto i : it)
		{
			std::cout << i << " ";
		}
		std::cout << "\n";
	}

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (mtr[i][j] == mtr[j][i])
				std::cout << "OK" << " ";
			else
				std::cout << "FL" << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
//-------------------------- REC
	pathInfo defPath;
	defPath.path.push_back(0);
	pathInfo resPath = findPathRecursive(mtr, mtr.size(), defPath, 0);

	for (size_t i = 0; i < resPath.path.size(); i++)
	{
		std::cout << resPath.path[i] << " ";
	}
	std::cout << "--" << resPath.len*2 << "\n" ;
	for (size_t i = 0; i < resPath.path.size()-1; i++)
	{
		std::cout << mtr[resPath.path[i]][resPath.path[i+1]] << " ";
	}
	std::cout << "\n";
	std::cout << "\n";
//-------------------------- REC
//-------------------------- COLONY
	std::srand(unsigned(std::time(NULL)));
	for (int i = 0; i < 10; i++)
	{
		environment env = setEnviroment(mtr.size());
		env.map = mtr;
		env.tMax = 400;

		pathInfo t = runColony(env);

		for (auto it : t.path)
			std::cout << it << " ";
		std::cout << "--" << t.len << "\n" ;

		for (size_t i = 0; i < t.path.size()-1; i++)
		{
			std::cout << mtr[t.path[i]][t.path[i+1]] << " ";
		}
		std::cout << "\n";
	}
//-------------------------- COLONY

	getchar();

	return 0;
}
