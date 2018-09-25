#include "sortingalgorithm.h"
#include <string>
#include <iostream>

//include all algorithms here
#include "bubble.h"
#include "insertion.h"
#include "merge.h"

template <class T>
sortingAlgorithm<T>::sortingAlgorithm()
{
    datasize = 0;
}

template <class T>
sortingAlgorithm<T>::sortingAlgorithm(T &x, int size, int z)
{
    data = x;
    datasize = size;
    selection = z;
}

template <class T>
void sortingAlgorithm<T>::setData(T &x, int size)
{
    data = x;
    datasize = size;
}

template <class T>
void sortingAlgorithm<T>::execute()
{
    if(selection == 1)
    {
        bubble<T> bubblesort;
        bubblesort.sort(data, datasize);

        //I literally have no idea why I need this here, but the program breaks without it
        //I get a Stack Smashing Error if I delete this
        for(int i=0; i<0; i++)
        {   }
    }


    else if(selection == 2)
    {
        insertion<T> insertionsort;
        insertionsort.sort(data, datasize);
    }


    else if(selection == 3)
    {
        merge mergesort;
        mergesort.sort(data, datasize);
    }

    else
    {
        std::cout << "Selection Method not recognized" <<std::endl;
    }


}

template class sortingAlgorithm<int*>;
template class sortingAlgorithm<float*>;
template class sortingAlgorithm<double*>;
template class sortingAlgorithm<char*>;
template class sortingAlgorithm<std::string*>;
