    #ifndef TS_BRUTE_H
#define TS_BRUTE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include "point.h"


class TS_Brute
{
private:

    bool viewMode;

public:

    TS_Brute();
    TS_Brute(bool);


    //iterates through the entire graph and outputs the shortest path
    void findPath(std::vector<point> graph, float &bestDist, std::vector<int> &bestPath);

    void pathCalc(std::vector<point> graph, std::vector<int> permutation, float &totalDistance, float &bestDist, std::vector<int> &bestPath);

    //finds the distance between two points
    float distanceCalc(point, point);

};

#endif // TS_BRUTE_H
