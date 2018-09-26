#ifndef MERGEint_H
#define MERGEint_H

#include <string>

class merge
{
public:

    merge();

    void sort(int* &a, int size);
    void sort(float* &a, int size);
    void sort(double* &a, int size);
    void sort(char* &a, int size);
    void sort(std::string * &a, int size);


    void mergesort(int* &a, int first, int last);
    void merging(int* &a, int first, int mid, int last);

};

#endif // MERGE_H
