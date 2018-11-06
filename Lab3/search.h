#ifndef SEARCH_H
#define SEARCH_H


#include "algorithm.h"
#include "ts_brute.h"
#include "ts_dp.h"
#include "documentation.h"


template <class T>
class search : public algorithm<T>
{
private:

    documentation documenter;

    T data;
    int selection;

    double speed;

    int* bestPath;
    float bestDist;

    bool viewMode;

public:

    //constructor
    search();

    //takes a file name and reads the input data from data sets
    void load(T &, int select, bool viewer);

    //executes the search algorithm
    void execute();

    //prints the solution to the screen
    void display();

    //prints algorithm name, execution time and number of records analyzed to screen
    void stats();

    //loads the corresponding algorithm to the interface
    void select(int);

    //changes the view mode
    void view(bool);

    //saves the solution to file path given
    void save();

    //expanded in the future
    void configure();
};

#endif // SEARCH_H
