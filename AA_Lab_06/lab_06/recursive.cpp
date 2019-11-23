#include "recursive.h"

pathInfo findPathRecursiveForAll(const MtrInt &map, const size_t amount)
{
    pathInfo best;
    pathInfo tmp;

	for (size_t i = 0; i < amount; i++)
    {
        pathInfo def;
        def.path.push_back(i);
        tmp = findPathRecursive(map, amount, def, i);

        if (best.len == 0)
            best = tmp;
        if (best.len > tmp.len)
            best = tmp;
    }

    return best;
}

pathInfo findPathRecursive(const MtrInt &map,const size_t amount, pathInfo currPath, size_t currCity)
{
	pathInfo tmp;
	pathInfo currBest;
	pathInfo nextPath;

	for (size_t i = 0; i < amount; i++)
	{
		nextPath = currPath;
		if (map[currCity][i] > 0 && !isInVector(currPath.path, i))
		{
			nextPath.path.push_back(i);
			nextPath.len += map[currCity][i];
			tmp = findPathRecursive(map, amount, nextPath, i);

			if (currBest.len == 0 && tmp.path.size() == amount)
				currBest = tmp;
			if (currBest.len > tmp.len && tmp.path.size() == amount)
				currBest = tmp;
		}
	}

	if (currBest.len == 0)
		currBest = currPath;

	return currBest;
}

