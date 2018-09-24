#ifndef SEARCH_H
#define SEARCH_H

#include "algorithm.h"
#include "source.h"



template <class T>
class search : public algorithm<T>
{
private:

    std::list<source> data;
    int datasize;
    int selection;
    double speed;

public:

    //constructor
    search();

    //takes a file name and reads the input data from data sets
    void load(std::list<source> &, int, int);

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

#endif // SEARCH_H
