#include <iostream>
#include <vector>
#include <recursive.h>
#include <antcolony.h>
#include <utility.h>

void test(std::string outFileName)
{
    MtrInt mtr = getMatrix();

    pathInfo recRes = findPathRecursiveForAll(mtr, mtr.size());
	std::cout << recRes.len << " <- RecLen (Prob. the best one)\n";
    for (auto it : recRes.path)
        std::cout << it << " ";
    std::cout << "\n" << "\n";

	int v = 5;
    std::vector<double> alphaTest = { 0, 0.2, 0.4, 0.5, 0.6, 0.8, 1 };
    std::vector<size_t> tMaxTest = { 10, 20, 40, 60, 80, 100, 220 };

    std::fstream outFile;
    outFile.open(outFileName, std::fstream::out);

    for (auto aIt : alphaTest)
    {
        for (auto tIt : tMaxTest)
        {
            environment env = setEnviroment(mtr);
            env.tMax = tIt;
            env.alpha = aIt;
            env.beta = 1 - aIt;

			env.Q = recRes.len % 100 * 10 + 50;

            int avg = 0;
            for (int k = 0; k < v; k++)
            {
                environment tEnv = env;
				pathInfo t = runColony(tEnv);
				std::cout << t.len << " ";
				if (t.len < recRes.len)
				{
					for(auto it : t.path)
					{
						std::cout << "- " << it << "\n";
					}
				}

                avg += t.len;
            }
			std::cout << env.alpha << " " << env.beta << " " << env.tMax << " " << avg/v << std::endl;
			outFile << env.alpha << " " << env.beta << " " << env.tMax << " " << avg/v << std::endl;
        }

		std::cout << "-----------------------------------\n";
    }

    outFile.close();
}

int main()
{
	std::srand(unsigned(std::time(NULL)));

	std::cout << "Test mode[y/n]?: ";
	std::string ans;
	std::getline(std::cin, ans);

	if (ans == "Y" || ans == "y")
	{
		std::string fName;

		std::cout << "Enter test file name: ";
		std::getline(std::cin, fName);

		test(fName);
	}
	else
	{
		MtrInt mtr = getMatrix();

		pathInfo recRes = findPathRecursiveForAll(mtr, mtr.size());

		std::cout << "Recursive res. len: " << recRes.len << std::endl;
		std::cout << "Path: ";
		for (auto it : recRes.path)
			std::cout << it << " ";

		std::cout << std::endl << std::endl;

		environment env = setEnviroment(mtr);
		pathInfo t = runColony(env);

		std::cout << "And colony res. len: " << t.len << std::endl;
		std::cout << "Path: ";
		for (auto it : t.path)
			std::cout << it << " ";
	}

	getchar();

	return 0;
}
