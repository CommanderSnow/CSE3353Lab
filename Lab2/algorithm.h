#ifndef ALGORITHM_H
#define ALGORITHM_H

template <class T>
class algorithm
{
private:
    T data;
    int datasize;
    int selection;
    double speed;

public:

    //takes a file name and reads the input data from data sets
    void load(T a, int x);

    //executes the search algorithm
    void execute();

    //prints the solution to the screen
    void display();

    //prints algorithm name, execution time and number of records analyzed to screen
    void stats();

    //loads the corresponding algorithm to the interface
    void select(int x);

    //saves the solution to file path given
    void save();

    //expanded in the future
    void configure();

};

#endif // ALGORITHM_H
