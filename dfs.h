#ifndef DFS_H
#define DFS_H

#include <stack>
#include <list>

#include "source.h"


class DFS
{
private:
    source  sourceNode;
    source destNode;
    std::stack<source> path;    //the saved path from source to destination


public:

    DFS();

    void search(std::list<source>&);

    void setSourceDest(int, int);

    source& findNode(std::list<source>& pathway, source x);


};

#endif // DFS_H
