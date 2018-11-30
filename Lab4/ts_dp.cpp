#include "ts_dp.h"

TS_DP::TS_DP()
{
    viewMode = false;
}

TS_DP::TS_DP(bool viewer)
{
    viewMode = viewer;
}

void TS_DP::findPath(std::vector<point> graph, float &bestDist, std::vector<int> &bestPath)
{
    int size = graph.size();

    //creates an X by X matrix of floats
    float** table = new float*[size];
    for(int i=0; i<size; i++)
    {   table[i] = new float[size]; }

    //populates the matrix with the distance calculations
    for(int i=0; i<size; i++)
    {
        for(int k=0; k<size; k++)
        {
            table[i][k] = distanceCalc(graph[i], graph[k]);
        }
    }


    std::vector<int> permutation;

    for(int i=0; i<size; i++)
    {
        permutation.push_back(i);
    }


    while(std::next_permutation(permutation.begin()+1, permutation.end()))
    {
        float totalDistance = 0;

        int k = 0;

        for(int i=0; i<size; i++)
        {
            totalDistance += table[k][permutation[i]];
            k = permutation[i];
        }

        totalDistance += table[k][0];


        if(totalDistance < bestDist)
        {
            bestDist = totalDistance;

            for(int i=0; i<size; i++)
            {
                bestPath[i] = graph[permutation[i]].getName();
            }
        }

    }

}



float TS_DP::distanceCalc(point start, point end)
{
    float Xdist = start.getX() - end.getX();
    float Ydist = start.getY() - end.getY();
    float Zdist = start.getZ() - end.getZ();

    return std::sqrt(Xdist * Xdist + Ydist * Ydist + Zdist * Zdist);
}

