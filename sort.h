#ifndef SORT_H
#define SORT_H
#include "algorithm.h"


template <class T>
class sort : public algorithm<T>
{
private:

    T data;
    int datasize;
    int selection;
    double speed;

public:

    //constructor
    sort();

    //takes a file name and reads the input data from data sets
    void load(T&, int, int);

    //executes the search algorithm
    void execute();

    //prints the solution to the screen
    void display();

    //prints algorithm name, execution time and number of records analyzed to screen
    void stats();

    //loads the corresponding algorithm to the interface
    void select(int);

    //saves the solution to file path given
    void save();

    //expanded in the future
    void configure();

};

#endif // SORT_H
