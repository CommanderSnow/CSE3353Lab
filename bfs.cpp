#include "bfs.h"
#include <string>


template <class T>
BFS<T>::BFS()
{

}


template class BFS<int*>;
template class BFS<float*>;
template class BFS<double*>;
template class BFS<char*>;
template class BFS<std::string*>;
