#ifndef SEARCH_H
#define SEARCH_H

#include "algorithm.h"
#include <list>
#include "source.h"



template <class T>
class search : public algorithm<T>
{
private:

    std::list<source> data;
    int start;
    int end;
    int selection;

    double speed;

    int NodesInPath;
    int NodesExplored;
    int distance;
    int cost;

public:

    //constructor
    search();

    //takes a file name and reads the input data from data sets
    void load(std::list<source> &, int select, int starter, int dest);

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
