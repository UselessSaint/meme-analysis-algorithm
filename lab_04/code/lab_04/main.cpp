#include "winmult.h"

mtr mtrGen(size_t size)
{
	mtr res;

	for (size_t i = 0; i < size; i++)
	{
		std::vector<double> tmp;
		for (size_t j = 0; j < size; j++)
		{
			tmp.push_back(1);
		}
		res.push_back(tmp);
	}

	return res;
}

void printMtr(mtr inp)
{
	for (auto row : inp)
	{
		for (auto el : row)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void makeTab(std::vector<std::pair<size_t, double>> infoForN, size_t N, bool ev)
{
	std::string name = "info_" + std::to_string(N);
	if (ev)
		name += "_ev";
	else
		name += "_nv";

	std::ofstream file(name + ".txt");

	file << "\\begin{tabular}{|c c|}\n";
	file << "\t\\hline\n";
	file << "\tРазмер & Время (с) \\\\\n";
	file << "\t\\hline\n";

	for (auto elem : infoForN)
	{
		file << "\t" + std::to_string(elem.first) + " & " + std::to_string(elem.second) + "\\\\\n";
		file << "\t\\hline\n";
	}

	file << "\\end{tabular}\n\n";

	file << "\\begin{filecontents}{" + name + ".dat}\n";

	for (auto elem : infoForN)
	{
		file << "\t" + std::to_string(elem.first) + " " + std::to_string(elem.second) + "\n";
	}

	file << "\\end{filecontents}\n";

	file.close();
}

void superTest()
{
	std::vector<size_t> trdsN = {1,2,4,8,16,32,64};

	for (auto N : trdsN)
	{
		std::vector<std::pair<size_t, double>> infoForN;

		for (size_t len = 100; len < 1010; len += 100)
		{
			mtr tst = mtrGen(len);

			double time = 0.0;

			for (int k = 0; k < 1; k++)
			{
				clock_t st = clock();
				multiply(tst, tst, N);
				clock_t end = clock();

				time += static_cast<double>(end - st) / CLOCKS_PER_SEC;
			}

			infoForN.push_back(std::pair<size_t, double>(len, time));
		}

		//makeTab(infoForN, N, false);
		makeTab(infoForN, N, true);
	}
}

int main()
{
	superTest();

	return 0;
}
