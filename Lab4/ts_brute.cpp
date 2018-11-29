#include "ts_brute.h"


TS_Brute::TS_Brute()
{
    viewMode = false;
}

TS_Brute::TS_Brute(bool viewer)
{
    viewMode = viewer;
}

void TS_Brute::findPath(std::vector<point> graph, float &bestDist, int *&bestPath)
{
    int size = graph.size();
    float totalDistance = 0;


    std::vector<int> permutation;

    for(int i=0; i<size; i++)
    {
        permutation.push_back(i);
    }

    pathCalc(graph, permutation, totalDistance, bestDist, bestPath);

    while(std::next_permutation(permutation.begin()+1, permutation.end()))
    {
        pathCalc(graph, permutation, totalDistance, bestDist, bestPath);
    }


}

void TS_Brute::pathCalc(std::vector<point> graph, std::vector<int> permutation, float &totalDistance, float &bestDist, int* &bestPath)
{
    int size = graph.size();
    totalDistance = distanceCalc(graph[permutation[0]], graph[permutation[size-1]]);

    for(int i=1; i<size; i++)
    {
        totalDistance += distanceCalc(graph[permutation[i-1]], graph[permutation[i]]);
    }

    if(totalDistance < bestDist)
    {
        bestDist = totalDistance;

        for(int i=0; i<size; i++)
        {
            bestPath[i] = graph[permutation[i]].getName();
        }
    }
}

float TS_Brute::distanceCalc(point start, point end)
{
    float Xdist = start.getX() - end.getX();
    float Ydist = start.getY() - end.getY();
    float Zdist = start.getZ() - end.getZ();

    return std::sqrt(Xdist * Xdist + Ydist * Ydist + Zdist * Zdist);
}


