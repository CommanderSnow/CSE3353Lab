#include "dijkstra.h"
#include <string>


template <class T>
dijkstra<T>::dijkstra()
{

}


template class dijkstra<int*>;
template class dijkstra<float*>;
template class dijkstra<double*>;
template class dijkstra<char*>;
template class dijkstra<std::string*>;
