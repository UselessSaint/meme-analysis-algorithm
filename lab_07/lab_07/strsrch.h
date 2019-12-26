#ifndef STRSRCH_H
#define STRSRCH_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

int standart(const std::string &str, const std::string &substr);
int kmp(std::string &str, std::string &substr);
int bm(std::string &str, std::string &substr);

#endif // STRSRCH_H
