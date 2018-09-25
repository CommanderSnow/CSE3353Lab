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
    std::queue<source> theQ;    //the stack that holds the possible destinations to travel to


public:

    BFS();

    void searchIterative(std::list<source>&);

    void searchRecursive(std::list<source>&);

    void recursiveFunc(source, std::vector<bool>&, std::list<source>&);

    void setSourceDest(int, int);

    source& findNode(std::list<source>& pathway, int x);


};

#endif // BFS_H
