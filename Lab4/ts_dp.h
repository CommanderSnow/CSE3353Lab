#ifndef TS_DP_H
#define TS_DP_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include "point.h"

class TS_DP
{
private:

    bool viewMode;

public:

    TS_DP();
    TS_DP(bool);

    //iterates through the entire graph and outputs the shortest path
    void findPath(std::vector<point> graph, float &bestDist, std::vector<int> &bestPath);

    //finds the distance between two points
    float distanceCalc(point start, point end);
};

#endif // TS_DP_H
