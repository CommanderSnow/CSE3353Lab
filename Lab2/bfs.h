#ifndef BFS_H
#define BFS_H

#include <queue>
#include <list>
#include <vector>

#include "source.h"

class BFS
{
private:
    source sourceNode;
    source destNode;
    std::list<source> pathway;
    std::queue<source> theQ;         //the stack that holds the possible destinations to travel to
    std::vector<int> path;           //the vector that holds a possible path from source to destination
    std::vector<int> bestPath;       //the vector that holds the best path from source to destination


    int NodesInPath;
    int NodesExplored;
    int distance;
    int cost;


public:

    BFS();

    void settings(std::list<source>, int, int);

    void searchIterative();

    void searchRecursive();

    void recursiveFunc(source, std::vector<bool>&);

    source& findNode(int x);

    void displayPath();

    void clear();

    int getPath();
    int getExplored();
    int getDistance();
    int getCost();

};

#endif // BFS_H
