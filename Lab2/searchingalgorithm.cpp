#include "searchingalgorithm.h"
#include <string>
#include <iostream>
#include "source.h"

//include all algorithms here
#include "dfs.h"
#include "bfs.h"
#include "dijkstra.h"
#include "astar.h"

template <class T>
searchingAlgorithm<T>::searchingAlgorithm()
{
    NodesInPath = 0;
    NodesExplored = 0;
    distance = 0;
    cost = 0;
}

template <class T>
searchingAlgorithm<T>::searchingAlgorithm(std::list<source> &graph, int select, int starter, int dest)
{
    data = graph;
    selection = select;
    start = starter;
    end = dest;

    NodesInPath = 0;
    NodesExplored = 0;
    distance = 0;
    cost = 0;
}

template <class T>
void searchingAlgorithm<T>::setData(std::list<source> &graph, int select, int starter, int dest)
{
    data = graph;
    selection = select;
    start = starter;
    end = dest;
}

template <class T>
void searchingAlgorithm<T>::execute()
{
    if(selection == 1)
    {
        DFS DFSsearch;
        DFSsearch.settings(data, start, end);
        DFSsearch.searchIterative();

        NodesInPath = DFSsearch.getPath();
        NodesExplored = DFSsearch.getExplored();
        distance = DFSsearch.getDistance();
        cost = DFSsearch.getCost();

        DFSsearch.clear();
    }

    else if(selection == 2)
    {
        DFS DFSsearch;
        DFSsearch.settings(data, start, end);
        DFSsearch.searchRecursive();

        NodesInPath = DFSsearch.getPath();
        NodesExplored = DFSsearch.getExplored();
        distance = DFSsearch.getDistance();
        cost = DFSsearch.getCost();

        DFSsearch.clear();
    }


    else if(selection == 3)
    {
        BFS BFSsearch;
        BFSsearch.settings(data, start, end);
        BFSsearch.searchIterative();

        NodesInPath = BFSsearch.getPath();
        NodesExplored = BFSsearch.getExplored();
        distance = BFSsearch.getDistance();
        cost = BFSsearch.getCost();

        BFSsearch.clear();
    }

    else if(selection == 4)
    {
        BFS BFSsearch;
        BFSsearch.settings(data, start, end);
        BFSsearch.searchRecursive();

        NodesInPath = BFSsearch.getPath();
        NodesExplored = BFSsearch.getExplored();
        distance = BFSsearch.getDistance();
        cost = BFSsearch.getCost();

        BFSsearch.clear();
    }

    else if(selection == 5)
    {
        dijkstra dijkstraSearch;
        dijkstraSearch.settings(data, start, end);
        dijkstraSearch.search();

        NodesInPath = dijkstraSearch.getPath();
        NodesExplored = dijkstraSearch.getExplored();
        distance = dijkstraSearch.getDistance();
        cost = dijkstraSearch.getCost();

        dijkstraSearch.clear();
    }

    else if(selection == 6)
    {
        AStar AStarSearch;
        AStarSearch.settings(data, start, end);
        AStarSearch.search();

        NodesInPath = AStarSearch.getPath();
        NodesExplored = AStarSearch.getExplored();
        distance = AStarSearch.getDistance();
        cost = AStarSearch.getCost();

        AStarSearch.clear();
    }


    else
    {
        std::cout << "Selection Method not recognized" <<std::endl;
    }


}

template <class T>
void searchingAlgorithm<T>::statistics()
{

}

template <class T>
int& searchingAlgorithm<T>::getPath()
{
    return NodesInPath;
}

template <class T>
int& searchingAlgorithm<T>::getExplored()
{
    return NodesExplored;
}

template <class T>
int& searchingAlgorithm<T>::getDistance()
{
    return distance;
}

template <class T>
int& searchingAlgorithm<T>::getCost()
{
    return cost;
}

template class searchingAlgorithm<int*>;
template class searchingAlgorithm<float*>;
template class searchingAlgorithm<double*>;
template class searchingAlgorithm<char*>;
template class searchingAlgorithm<std::string*>;
