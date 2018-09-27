#ifndef DFS_H
#define DFS_H

#include <stack>
#include <list>
#include <vector>

#include "source.h"


class DFS
{
private:
    source sourceNode;
    source destNode;
    std::list<source> pathway;
    std::stack<source> theStack;    //the stack that holds the possible destinations to travel to
    std::vector<int> bestPath;      //the vector that holds the best path from source to destination


    int NodesInPath;
    int NodesExplored;
    int distance;
    int cost;

public:

    DFS();

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

#endif // DFS_H
