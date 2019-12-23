#ifndef WINMULT_H
#define WINMULT_H

#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <time.h>

typedef std::vector<std::vector<double>> mtr;

mtr multiply(mtr &A, mtr &B, size_t thdN);

#endif // WINMULT_H
