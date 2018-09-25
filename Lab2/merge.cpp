#include "merge.h"
#include <string>
#include <iostream>


merge::merge()
{

}

void merge::sort(int* &a, int size)
{
    mergesort(a, 0, size);
}


//Had difficulties with Merge Sort while it was Templated
//This is more work, but I will code in a different Merge Sort for each necessary data type as needed
void merge::sort(float* &a, int size)
{   }
void merge::sort(double* &a, int size)
{   }
void merge::sort(char* &a, int size)
{   }
void merge::sort(std::string* &a, int size)
{   }


void merge::mergesort(int* &a, int first, int last)
{
    if(first<last)
    {
        int mid = first+(last-first)/2;

        mergesort(a, first, mid);
        mergesort(a, mid+1, last);

        merging(a, first, mid, last);
    }

}

void merge::merging(int* &a, int first, int mid, int last)
{
    //these variables are used for calulations
    int var1 = mid - first + 1;
    int var2 = last - mid;

    //these are temporary arrays to split the data
    int arr1[var1];
    int arr2[var2];

    //puts the first half into the first array
    for(int i=0; i<var1; i++)
    {   arr1[i] = a[first + i]; }

    //puts the second half into the second array
    for(int i=0; i<var2; i++)
    {   arr2[i] = a[mid+1+i];  }

    //used for the indexes of arr1, arr2, and a
    int i =0;
    int j = 0;
    int k = first;

    //this loop continues until one reaches the end of an array
    while(i<var1 && j<var2)
    {
        //if the element in the first array is smaller, move it into the main array
        if(arr1[i]<=arr2[j])
        {
            a[k] = arr1[i];
            i++;
        }

        //if the element in the second array is smaller, move it into the main array
        else
        {
            a[k] = arr2[j];
            j++;
        }

        //increament the index for the main array
        k++;
    }

    //copies the rest of the array over if there are leftovers
    while(i<var1)
    {
        a[k] = arr1[i];
        i++;
        k++;
    }

    //copies the rest of the array over if there are leftovers
    while(j<var2)
    {
        a[k] = arr2[j];
        j++;
        k++;
    }

}

