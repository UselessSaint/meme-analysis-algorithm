#include "winmult.h"

void thrdMultiply(mtr &res, const mtr &A, const mtr &B, int st, int end, std::mutex &mtx)
{
	size_t B_rows = B.size(), B_cols = B[0].size();

	bool uneven = (B_rows % 2 != 0 ? true : false);

	for (size_t i = size_t(st); i < size_t(end); i++)
	{
		for (size_t j = 0; j < B_cols; j++)
		{
			for (size_t k = 0; k < B_rows-1; k+=2)
			{

				res[i][j] += (A[i][k] + B[k+1][j])*(A[i][k+1] + B[k][j]);

			}

			if (uneven)
				res[i][j] += A[i][B_rows-1] * B[B_rows-1][j];
		}
	}
}

mtr multiply(mtr &A, mtr &B, size_t thdN)
{
	std::mutex mtx;

	size_t A_rows = A.size(), A_cols = A[0].size();
	size_t B_rows = B.size(), B_cols = B[0].size();
	mtr res;

	if (A_cols != B_rows)
	{
		return res;
	}

	std::vector<double> preCalc1;
	std::vector<double> preCalc2;

	for (size_t i = 0; i < A_rows; i++)
	{
		double sum = 0;

		for (size_t j = 0; j < (A_cols % 2 == 0 ? A_cols : A_cols - 1); j += 2)
		{
			sum += A[i][j]*A[i][j+1];
		}

		preCalc1.push_back(-1*sum);
	}

	for (size_t i = 0; i < B_cols; i++)
	{
		double sum = 0;

		for (size_t j = 0; j < (B_rows % 2 == 0 ? B_rows : B_rows - 1); j += 2)
		{
			sum += B[j][i]*B[j+1][i];
		}

		preCalc2.push_back(-1*sum);
	}

	for (size_t i = 0; i < A_rows; i++)
	{
		std::vector<double> tmp;
		for (size_t j = 0; j < B_cols; j++)
		{
			tmp.push_back(preCalc1[i] + preCalc2[j]);
		}

		res.push_back(tmp);
	}

	if (thdN > A_rows)
		thdN = A_rows;

	int step = int(A_rows / thdN);

	std::vector<std::thread> thds;

	int st;
	int end;

	for (int i = 0; i < int(thdN); i++)
	{
		st = step*i;
		end = step*(i+1);
		if (i == int(thdN - 1))
			end = int(A_rows);

		std::thread thread(thrdMultiply, std::ref(res), std::ref(A), std::ref(B), st, end, std::ref(mtx));
		thds.push_back(std::move(thread));
	}

	for (auto &thd : thds)
		if (thd.joinable())
			thd.join();

	return res;
}











