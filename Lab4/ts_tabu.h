#ifndef TS_TABU_H
#define TS_TABU_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include "point.h"

using std::vector;


class TS_Tabu
{
private:

    bool viewMode;
    float** table;
    int size;

    vector<int> TabuList;   //determines which points cannot be swapped
    int tabuPtr = 0;
    int tabuSize = 30;      //determines how many paths are stored in the Tabu List

public:

    TS_Tabu();
    TS_Tabu(bool);

    //iterates through the entire graph and outputs the shortest path
    void findPath(vector<point> graph, float &bestDist, std::vector<int> &bestPath);

    //gets the length of the path
    float getLength(vector<int> neighbor);

    //creates a neighbor
    bool createNeighbor(vector<vector<int>>& neighborhood, vector<int> initialState);

    //finds the distance between two points
    float distanceCalc(point start, point end);
};

#endif // TS_Tabu
