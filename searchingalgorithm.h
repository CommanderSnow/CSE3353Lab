#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H


template <class T>
class searchingAlgorithm
{
private:

    T data;
    int datasize;
    int selection;


public:

    searchingAlgorithm();
    searchingAlgorithm(T&, int, int);

    void setData(T&, int);

    void execute();

};

#endif // SEARCHINGALGORITHM_H
