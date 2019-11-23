#include "utility.h"

bool isInVector(std::vector<size_t> path, size_t city)
{
	for (auto it : path)
	{
		if (city == it)
			return true;
	}

	return false;
}

MtrInt getMatrix()
{
	MtrInt mtr;
	std::string fileName;
	std::cout << "Enter file name: ";
	getline(std::cin, fileName);

	std::ifstream file(fileName);

	std::string tmp;

	if (file.is_open())
	{
		file >> tmp;
		int size = std::stoi(tmp);

		for (int i = 0; i < size; i++)
		{
			std::vector<int> row;
			for (int j = 0; j < size; j++)
			{
				int tmpInt;
				file >> tmpInt;

				row.push_back(tmpInt);
			}
			mtr.push_back(row);
		}
	}
	else
	{
		std::cout << "File not found.";
	}

	return mtr;
}

environment setEnviroment(MtrInt &mtr)
{
	environment env;

    MtrInt map = mtr;
    size_t cities = mtr.size();

	env.map = map;
	env.cities = cities;

	for (size_t i = 0; i < cities; i++)
	{
		std::vector<double> tmpTau;
		std::vector<double> tmpDTau;
		for (size_t j = 0; j < cities; j++)
		{
			tmpTau.push_back(env.minTau);
			tmpDTau.push_back(0);
		}
		env.tau.push_back(tmpTau);
		env.dTau.push_back(tmpDTau);
	}

	return env;
}
