#include "datasets.h"
#include "documentation.h"
#include <iostream>

using std::cout;
using std::endl;


datasets::datasets()
{
    data = new int;
    datasize = 0;
}

void datasets::storeData()
{
    documentation<int*> storer;

    fileX = datatype;

    //see how the files are ordered in documentation.cpp
    //since there are 4 datatypes, just add 4 for move to the next file size
    if(datasize >= 1000)
    {   fileX += 4;  }

    if(datasize >= 10000)
    {   fileX += 4;  }

    if(datasize >= 100000)
    {   fileX += 4; }

    storer.storeFile(data, datasize, fileX);
}

void datasets::createData(int a)
{
    if(datasize<1 || datasize>100000)
    {
        cout << "Size does not match boundries, defaulting to 10" <<endl;
        setSize(10);
    }

    srand(time(NULL));
    //delete data;
    data = new int[datasize];

    //a = 1 == Random
    if(a==1)
    {
        for(int i=0; i<datasize; i++)
        {   data[i] = rand() % datasize;    }

        datatype = 1;
    }

    //a = 2 == Reversed Sorted
    else if(a==2)
    {
        for(int i=0; i<datasize; i++)
        {   data[i] = (datasize-i); }

        datatype = 2;
    }

    //a = 3 == 20% Unique Values
    else if(a==3)
    {
        int unique[5];

        //selects the 5 unique values
        for(int i=0; i<5; i++)
        {
            unique[i] = rand() % datasize;
            data[i] = unique[i];
        }

        for(int i=5; i<datasize; i++)
        {   data[i] = unique[rand() % 5];   }

        datatype = 3;
    }

    //a = 4 == 30% Random
    else if(a==4)
    {
        int percent = datasize * .3;

        for(int i=0; i<(datasize-percent); i++)
        {   data[i] = i+1;    }

        for(int i=(datasize-percent); i<datasize; i++)
        {   data[i] = rand() % datasize;}

        datatype = 4;
    }

    else
    {
        cout << "Not a valid data set type, defaulting to Random Dataset." <<endl;
        createData(1);
        return;
    }

    storeData();
}

int datasets::getFile()
{
    return fileX;
}


int& datasets::getSize()
{
    return datasize;
}


void datasets::setSize(int x)
{
    datasize = x;
}

void datasets::viewData()
{

    if(datasize<1)
    {
        cout << "No data stored" <<endl;
        return;
    }

    for(int i=0; i<datasize; i++)
    {
        cout << data[i] << " ";
    }

    cout <<endl;
}

void datasets::displayType()
{
    if(datatype == 1)
    {
        cout << "DATASET IS RANDOMIZED WITH " << datasize << " ELEMENTS" <<endl;
    }

    else if(datatype == 2)
    {
        cout << "DATASET IS REVERSED ORDER WITH " << datasize << " ELEMENTS" <<endl;
    }

    else if(datatype == 3)
    {
        cout << "DATASET IS 20% UNIQUE VALUES WITH " << datasize << " ELEMENTS" <<endl;
    }

    else if(datatype == 4)
    {
        cout << "DATASET IS 30% RANDOM WITH " << datasize << " ELEMENTS" <<endl;
    }

}

int*& datasets::getData()
{
    return data;
}


void datasets::deleteData()
{
    delete[] data;
}
