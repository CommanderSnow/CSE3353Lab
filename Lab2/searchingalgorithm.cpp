#include "searchingalgorithm.h"
#include <string>
#include <iostream>

//include all algorithms here
#include "dfs.h"
#include "bfs.h"
#include "dijkstra.h"
#include"astar.h"

template <class T>
searchingAlgorithm<T>::searchingAlgorithm()
{
    datasize = 0;
}

template <class T>
searchingAlgorithm<T>::searchingAlgorithm(T &x, int size, int z)
{
    data = x;
    datasize = size;
    selection = z;
}

template <class T>
void searchingAlgorithm<T>::setData(T &x, int size)
{
    data = x;
    datasize = size;
}

template <class T>
void searchingAlgorithm<T>::execute()
{
    if(selection == 1)
    {
        DFS DFSsearch;
        //DFSsearch.search(data, datasize);
    }


    else if(selection == 2)
    {
        BFS<T> BFSsearch;
        //BFS.search(data, datasize);
    }


    else if(selection == 3)
    {
        dijkstra<T> dijkstraSearch;
        //dijkstraSearch.search(data, datasize);
    }

    else if(selection == 4)
    {
        AStar<T> AStarSearch;
        //AStarSearch.search(data, datasize);
    }


    else
    {
        std::cout << "Selection Method not recognized" <<std::endl;
    }


}

template class searchingAlgorithm<int*>;
template class searchingAlgorithm<float*>;
template class searchingAlgorithm<double*>;
template class searchingAlgorithm<char*>;
template class searchingAlgorithm<std::string*>;
