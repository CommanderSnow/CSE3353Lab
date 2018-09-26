#include "insertion.h"
#include <string>

template <class T>
insertion<T>::insertion()
{

}

template <class T>
void insertion<T>::sort(T &a, int size)
{
    int j;
    T temp;

    for(int i = 1; i<size; i++)
    {
        j = i;
        while(j>0 && a[j-1]>a[j])
        {
            *temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = *temp;
            j--;
        }
    }
}




template class insertion<int*>;
template class insertion<float*>;
template class insertion<double*>;
template class insertion<char*>;
template class insertion<std::string*>;
