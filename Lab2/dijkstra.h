#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <queue>
#include <list>
#include "source.h"

class dijkstra
{
private:
    source sourceNode;
    source destNode;
    std::list<source> pathway;
    std::priority_queue<std::pair<int, std::vector<source>>> thePQ;    //the priority queue to hold what to search for next
    std::vector<source> bestPath;                                      //the vector that holds the best path from source to destination


    int NodesInPath;
    int NodesExplored;
    int distance;
    int cost;

public:

    dijkstra();

    void settings(std::list<source>, int, int);

    void search();

    source& findNode(int x);

    void displayPath();

    void clear();

    int getPath();
    int getExplored();
    int getDistance();
    int getCost();

};

#endif // DIJKSTRA_H
