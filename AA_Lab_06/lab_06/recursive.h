#ifndef RECURSIVE_H
#define RECURSIVE_H

#include <utility.h>

pathInfo findPathRecursiveForAll(const MtrInt &map, const size_t amount);
pathInfo findPathRecursive(const MtrInt &map,const size_t amount, pathInfo currPath, size_t currCity);

#endif // RECURSIVE_H
