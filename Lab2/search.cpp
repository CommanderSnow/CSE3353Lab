#include "search.h"
#include "searchingalgorithm.h"
#include "documentation.h"


#include <iostream>
#include <chrono>
#include <string>

using std::cout;
using std::endl;
using namespace std::chrono;

template <class T>

search<T>::search()
{
    speed = 0;
    selection = 0;

    NodesInPath = 0;
    NodesExplored = 0;
    distance = 0;
    cost = 0;
}

//takes a file name and reads the input data from data sets
template <class T>
void search<T>::load(std::list<source> &a, int select, int starter, int dest)
{
    data = a;
    selection = select;
    start = starter;
    end = dest;
}

//executes the search algorithm
template <class T>
void search<T>::execute()
{
    searchingAlgorithm<T> searchy(data, selection, start, end);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    searchy.execute();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    speed = time_span.count();

    NodesInPath = searchy.getPath();
    NodesExplored = searchy.getExplored();
    distance = searchy.getDistance();
    cost = searchy.getCost();
}

//prints the solution to the screen
template <class T>
void search<T>::display()
{
    //for(int i=0; i<datasize; i++)
    //{   cout << data[i] << " "; }
    //cout <<endl;
}

//Prints algorithm name, execution time and number of records analyzed to screen
template <class T>
void search<T>::stats()
{
    if(selection == 1)
    {
        cout << "DFS Iterative: " <<endl;
        cout << "Nodes in Path - (" << NodesInPath << ") ";
        cout << "Nodes Explored - (" << NodesExplored << ") " <<endl;

        cout << "The distance traveled is (" << distance << ") ";
        cout << "The cost is (" << cost << ") " <<endl;

        cout << "It took: " << speed << " seconds to complete." <<endl <<endl;
    }

    else if(selection == 2)
    {
        cout << "DFS Recursive: " <<endl;
        cout << "Nodes in Path - (" << NodesInPath << ") ";
        cout << "Nodes Explored - (" << NodesExplored << ") " <<endl;

        cout << "The distance traveled is (" << distance << ") ";
        cout << "The cost is (" << cost << ") " <<endl;

        cout << "It took: " << speed << " seconds to complete." <<endl <<endl;
    }

    else if(selection == 3)
    {
        cout << "BFS Iterative: " <<endl;
        cout << "Nodes in Path - (" << NodesInPath << ") ";
        cout << "Nodes Explored - (" << NodesExplored << ") " <<endl;

        cout << "The distance traveled is (" << distance << ") ";
        cout << "The cost is (" << cost << ") " <<endl;

        cout << "It took: " << speed << " seconds to complete." <<endl <<endl;
    }

    else if(selection == 4)
    {
        cout << "BFS Recursive: " <<endl;
        cout << "Nodes in Path - (" << NodesInPath << ") ";
        cout << "Nodes Explored - (" << NodesExplored << ") " <<endl;

        cout << "The distance traveled is (" << distance << ") ";
        cout << "The cost is (" << cost << ") " <<endl;

        cout << "It took: " << speed << " seconds to complete." <<endl <<endl;
    }

    else if(selection == 5)
    {
        cout << "Dijkstra: " <<endl;
        cout << "Nodes in Path - (" << NodesInPath << ") ";
        cout << "Nodes Explored - (" << NodesExplored << ") " <<endl;

        cout << "The distance traveled is (" << distance << ") ";
        cout << "The cost is (" << cost << ") " <<endl;

        cout << "It took: " << speed << " seconds to complete." <<endl<<endl;
    }

    else if(selection == 6)
    {
        cout << "AStar: " <<endl;
        cout << "Nodes in Path - (" << NodesInPath << ") ";
        cout << "Nodes Explored - (" << NodesExplored << ") " <<endl;

        cout << "The distance traveled is (" << distance << ") ";
        cout << "The cost is (" << cost << ") " <<endl;

        cout << "It took: " << speed << " seconds to complete." <<endl <<endl;
    }

}

//loads the corresponding algorithm to the interface
template <class T>
void search<T>::select(int x)
{
    selection = x;
}

//saves the solution to file path given
template <class T>
void search<T>::save()
{
    documentation<T> saver;
    saver.saveFile(NodesInPath, NodesExplored, speed, distance, cost);
}

//expanded in the future
template <class T>
void search<T>::configure()
{
    //will be used in the future
}

template class search<int*>;
//template class search<float*>;
//template class search<double*>;
//template class search<char*>;
//template class search<std::string*>;
