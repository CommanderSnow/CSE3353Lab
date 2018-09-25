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
    std::stack<source> theStack;    //the stack that holds the possible destinations to travel to


public:

    DFS();

    void searchIterative(std::list<source>&);

    void searchRecursive(std::list<source>&);

    void recursiveFunc(source, std::vector<bool>&, std::list<source>&);

    void setSourceDest(int, int);

    source& findNode(std::list<source>& pathway, int x);


};

#endif // DFS_H
