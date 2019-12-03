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
	std::vector<double> alphaTest = { 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1 };
	std::vector<size_t> tMaxTest = { 10, 30, 50, 70, 90, 110, 130 };

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
			double avgT = 0;
            for (int k = 0; k < v; k++)
            {
                environment tEnv = env;
				clock_t st = clock();
				pathInfo t = runColony(tEnv);
				clock_t end = clock();
				std::cout << t.len << " ";

				avgT += static_cast<double>(end - st) / CLOCKS_PER_SEC;
                avg += t.len;
            }
			std::cout << env.alpha << " " << env.beta << " " << env.tMax << " " << avg/v << " " << avgT/v << std::endl;
			outFile << env.alpha << " " << env.beta << " " << env.tMax << " " << avg/v << " " << avgT/v << std::endl;
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
        MtrInt mtr = getMatrix();

        clock_t st = clock();

        pathInfo resRec = findPathRecursiveForAll(mtr, mtr.size());

        clock_t end = clock();

        double tm = static_cast<double>(end - st) / CLOCKS_PER_SEC;

        std::cout << "ResRec len.: " << resRec.len << std::endl;
        std::cout << "ResRec path.: ";
        for (auto it : resRec.path)
            std::cout << it << " ";
        std::cout << std::endl;

        std::cout << "ResRec time.: " << tm << std::endl;

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
