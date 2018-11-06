#include "search.h"
//#include "documentation.h"


#include <iostream>
#include <chrono>
#include <string>

using std::cout;
using std::endl;
using namespace std::chrono;

template <class T>

search<T>::search()
{
    data = documenter.getGraph();
    documenter.clearSave();
    speed = 0;
    selection = 0;    
    viewMode = false;
    bestDist = 999999;                //may lead to cases where best distance is never found because its higher than 99999, just make this bigger to fix it
}

//overides the graph data and provides additional information for the algorithm
template <class T>
void search<T>::load(T &a, int select, bool viewer)
{
    data = a;
    selection = select;

    bestPath = new int[a.size()];
    viewMode = viewer;
}

//executes the path finding algorithm
template <class T>
void search<T>::execute()
{    
    if(selection == 1)
    {
        TS_Brute brutalizer(viewMode);

        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        brutalizer.findPath(data, bestDist, bestPath);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();

        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        speed = time_span.count();
    }

    else if(selection == 2)
    {
        TS_Brute brutalizer(viewMode);
        TS_DP dynamisizer(viewMode);

        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        dynamisizer.findPath(data, bestDist, bestPath);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();

        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        speed = time_span.count();
    }


}

//prints the solution to the screen
template <class T>
void search<T>::display()
{
    //reserved for future use
}

//Prints algorithm name, the path, and the execution time.
template <class T>
void search<T>::stats()
{
    if(selection == 1)
    {
        std::cout << "The shortest path for Brute Force is: " << bestPath[0];

        for(int i=1; i<data.size(); i++)
        {
            std::cout << "->" << bestPath[i];
        }

        std::cout << " | Distance: " << bestDist <<std::endl;

        std::cout << "Time taken: " << speed <<std::endl;
    }

    else if(selection == 2)
    {
        std::cout << "The shortest path for Dynamic Programming is: " << bestPath[0];

        for(int i=1; i<data.size(); i++)
        {
            std::cout << "->" << bestPath[i];
        }

        std::cout << " | Distance: " << bestDist <<std::endl;

        std::cout << "Time taken: " << speed <<std::endl;
    }

}

//loads the corresponding algorithm to the interface
template <class T>
void search<T>::select(int x)
{
    selection = x;
}

//changes the view mode
template <class T>
void search<T>::view(bool viewer)
{
    viewMode = viewer;
}

//saves the solution to file path given
template <class T>
void search<T>::save()
{    
    documenter.saveFile(selection, speed, bestPath, bestDist, data.size());
}

//expanded in the future
template <class T>
void search<T>::configure()
{
    //will be used in the future
}

template class search<std::vector<point>>;

