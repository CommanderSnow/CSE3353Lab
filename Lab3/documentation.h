#ifndef DOCUMENTATION_H
#define DOCUMENTATION_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "point.h"


using std::string;


class documentation
{
private:

    string argv[20];
    int argf;
    int argc;

    std::vector<point> graph;

public:

    documentation();

    //gets the number of nodes within the
    int fileSize();

    //reads and constructs the list
    void buildGraph();

    //gets the graph
    std::vector<point>& getGraph();

    //erases the current save file
    void clearSave();

    //saves the graph
    void saveFile(int selection, double speed, int* bestPath, float bestDist, int size);

};

#endif // DOCUMENTATION_H
