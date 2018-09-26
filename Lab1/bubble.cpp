#include "bubble.h"
#include <string>
#include <iostream>

template <class T>
bubble<T>::bubble()
{

}

template <class T>
void bubble<T>::sort(T &a, int size)
{
    T k;

    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(a[i]>a[j])
            {
                *k = a[i];
                a[i] = a[j];
                a[j] = *k;
            }
        }
    }
}



template class bubble<int*>;
template class bubble<float*>;
template class bubble<double*>;
template class bubble<char*>;
template class bubble<std::string*>;
