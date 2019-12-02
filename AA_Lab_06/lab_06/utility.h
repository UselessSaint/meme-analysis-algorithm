#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <fstream>
#include <string>
#include <chrono>
#include <time.h>

typedef std::vector<std::vector<int>> MtrInt;
typedef std::vector<std::vector<double>> MtrDouble;

struct pathInfo
{
	std::vector<size_t> path;
	size_t len = 0;
};

struct environment
{
	MtrInt map;
	size_t cities;
	MtrDouble tau;
	MtrDouble dTau;
	double alpha = 0.5;
	double beta = 0.5;
	double ro = 0.5;
    double Q = 20;
	size_t tMax = 10;
	double minTau = 1;
};

bool isInVector(std::vector<size_t> path, size_t city);
MtrInt getMatrix();
environment setEnviroment(MtrInt &mtr);

#endif // UTILITY_H
