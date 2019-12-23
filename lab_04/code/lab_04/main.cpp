#include "winmult.h"

int main()
{
	mtr A;
	A.push_back(std::vector<double>({1, 2}));
	A.push_back(std::vector<double>({3, 4}));
	A.push_back(std::vector<double>({5, 6}));

	mtr B;
	B.push_back(std::vector<double>({1, 2, 3}));
	B.push_back(std::vector<double>({4, 5, 6}));

	auto res = multiply(A, B, 3);


	for (auto ait : A)
	{
		for (auto ai : ait)
		{
			std::cout << ai << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (auto ait : B)
	{
		for (auto ai : ait)
		{
			std::cout << ai << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (auto ait : res)
	{
		for (auto ai : ait)
		{
			std::cout << ai << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
