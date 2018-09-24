#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stack>

template <class T>
class dijkstra
{
private:
    int source;
    int destination;
    std::stack<T> path;    //the saved path from source to destination


public:
    dijkstra();
};

#endif // DIJKSTRA_H
