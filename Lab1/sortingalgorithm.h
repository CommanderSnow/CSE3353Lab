#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H


template <class T>
class sortingAlgorithm
{
private:

    T data;
    int datasize;
    int selection;


public:

    sortingAlgorithm();
    sortingAlgorithm(T&, int, int);

    void setData(T&, int);

    void execute();

};

#endif // SORTINGALGORITHM_H
