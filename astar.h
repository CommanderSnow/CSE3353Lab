#ifndef ASTAR_H
#define ASTAR_H

#include <stack>

template <class T>
class AStar
{
private:
    int source;
    int destination;
    std::stack<T> path;    //the saved path from source to destination

public:
    AStar();
};

#endif // ASTAR_H
