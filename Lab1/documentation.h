#ifndef DOCUMENTATION_H
#define DOCUMENTATION_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

using std::string;


template <class T>
class documentation
{
private:

    string argv[20];
    int argf;
    int argc;


public:

    documentation();

    //stores the data into a specified file
    void storeFile(T&, int, int);

    //load the data from the specified file
    void loadFile(T&, int, int);

    //saves the data to the SaveFile
    void saveFile(T&, int);

};

#endif // DOCUMENTATION_H
