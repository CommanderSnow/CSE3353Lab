#ifndef DATASETS_H
#define DATASETS_H


class datasets
{
private:

    int* data;
    int datasize;
    int datatype;

    //used for the documentation
    int fileX;

    //stores the data into the specified file
    void storeData();

public:

    //constructor
    datasets();

    //creates a data set of the secified type and size; a = data type
    //a = 1 == Random
    //a = 2 == Reversed Sorted
    //a = 3 == 20% Unique Values
    //a = 4 == 30% Random
    void createData(int a);

    //retrieves the location of the last stored file
    int getFile();

    //gets and sets the size of the dataset
    int &getSize();
    void setSize(int x);

    //prints out the data stored inside
    void viewData();

    //displays which data type has been created
    void displayType();

    //retrieves the data for usage
    int*& getData();

    //clears out the previous data set
    void deleteData();

};

#endif // DATASETS_H
