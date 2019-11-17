#ifndef ANTCOLONY_H
#define ANTCOLONY_H

#include <utility.h>

pathInfo runColony(environment &env);
pathInfo runAnt(environment &env, size_t baseCity);
void recalculateTau(environment &env);

#endif // ANTCOLONY_H
