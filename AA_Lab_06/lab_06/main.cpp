#include <iostream>
#include <vector>
#include <recursive.h>
#include <antcolony.h>
#include <utility.h>

void test(std::string outFileName)
{
    MtrInt mtr = getMatrix();

    pathInfo recRes = findPathRecursiveForAll(mtr, mtr.size());
    std::cout << recRes.len*2 << "<- RecLen (Prob. the best one)\n";
    for (auto it : recRes.path)
        std::cout << it << " ";
    std::cout << "\n" << "\n";

    int v = 20;
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

            env.Q = recRes.len*2 % 1000 - recRes.len*2 % 100 - recRes.len*2 % 10;

            int avg = 0;
            for (int k = 0; k < v; k++)
            {
                environment tEnv = env;
                pathInfo t = runColony(tEnv);
                std::cout << t.len << " ";

                avg += t.len;
            }

            outFile << env.alpha << " " << env.beta << " " << env.tMax << " " << avg/v << std::endl;
        }
    }

    outFile.close();
}

int main()
{
    test("mtrTest.txt");

    /*MtrInt mtr = getMatrix();

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
    pathInfo resPath = findPathRecursiveForAll(mtr, mtr.size());

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
    for (int i = 0; i < 1; i++)
	{
        environment env = setEnviroment(mtr);
        env.tMax = 1;

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


    pathInfo recRes = findPathRecursiveForAll(mtr, mtr.size());
    std::cout << recRes.len*2 << "<- RecLen (Prob. the best one)\n";
    for (auto it : recRes.path)
        std::cout << it << " ";
    std::cout << "\n" << "\n";

	int v = 20;
    std::vector<double> alphaTest = { 0, 0.2, 0.4, 0.5, 0.6, 0.8, 1 };
	std::vector<size_t> tMaxTest = { 10, 20, 40, 60, 80, 100, 220 };

    for (auto aIt : alphaTest)
    {
        for (auto tIt : tMaxTest)
        {
            environment env = setEnviroment(mtr);
            env.tMax = tIt;
            env.alpha = aIt;
            env.beta = 1 - aIt;

			env.Q = recRes.len*2 % 1000 - recRes.len*2 % 100 - recRes.len*2 % 10;

			int avg = 0;
			for (int k = 0; k < v; k++)
			{
				environment tEnv = env;
				pathInfo t = runColony(tEnv);
				std::cout << t.len << " ";
				if (t.len == 0)
					k -= 1;
				if (t.len < 600)
				{
					for (auto M : t.path)
						std::cout << std::endl << M;
					std::cout << std::endl;
				}

				avg += t.len;
			}

			std::cout << env.alpha << " " << env.beta << " " << env.tMax << " " << env.Q;
			std::cout << " -- " << avg/v << "\n" << "--" << "\n";
        }
        std::cout << "\n";
	}

*/
	getchar();

	return 0;
}
