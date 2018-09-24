#ifndef BFS_H
#define BFS_H

#include <stack>

template <class T>
class BFS
{
private:
    int source;
    int destination;
    std::stack<T> path;    //the saved path from source to destination

public:
    BFS();
};

#endif // BFS_H
