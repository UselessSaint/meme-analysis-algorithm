#include "recursive.h"


pathInfo findPathRecursive(const MtrInt &map,const size_t amount, pathInfo currPath, size_t currCity)
{
	pathInfo tmp;
	pathInfo currBest;
	pathInfo nextPath;

	for (auto it : currPath.path)
		std::cout << it << " ";
	std::cout << "\n";

	for (size_t i = 0; i < amount; i++)
	{
		nextPath = currPath;
		if (map[currCity][i] > 0 && !isInVector(currPath.path, i))
		{
			nextPath.path.push_back(i);
			nextPath.len += map[currCity][i];
			tmp = findPathRecursive(map, amount, nextPath, i);

			if (currBest.len == 0)
				currBest = tmp;
			if (currBest.len > tmp.len)
				currBest = tmp;
		}
	}

	if (currBest.len == 0)
		currBest = currPath;

	return currBest;
}

