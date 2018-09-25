#include "astar.h"
#include <string>


template <class T>
AStar<T>::AStar()
{

}


template class AStar<int*>;
template class AStar<float*>;
template class AStar<double*>;
template class AStar<char*>;
template class AStar<std::string*>;
