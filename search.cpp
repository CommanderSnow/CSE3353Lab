#include "search.h"
#include "sortingalgorithm.h"
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
    datasize = 0;
    speed = 0;
    selection = 0;
}

//takes a file name and reads the input data from data sets
template <class T>
void search<T>::load(std::list<source> &a, int x, int z)
{
    data = a;

    if(x<0)
    {
        cout << "datasize out of bounds, defaulting to 10" <<endl;
        x = 10;
    }

    datasize = x;
    selection = z;
    speed = 0;
}

//executes the search algorithm
template <class T>
void search<T>::execute()
{
    //sortingAlgorithm<T> sorty(data, datasize, selection);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    //sorty.execute();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    speed = time_span.count();
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
        cout << "Bubble Sort at " << datasize << " elements. ";
    }

    else if(selection == 2)
    {
        cout << "Insertion Sort at " << datasize << " elements. ";
    }

    else if(selection == 3)
    {
        cout << "Merge Sort at " << datasize << " elements. ";
    }

    cout << "It took: " << speed << " seconds to complete." <<endl;
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
    //saver.saveFile(data, datasize);
}

//expanded in the future
template <class T>
void search<T>::configure()
{
    //will be used in the future
}

//template class search<int*>;
//template class search<float*>;
//template class search<double*>;
//template class search<char*>;
//template class search<std::string*>;
