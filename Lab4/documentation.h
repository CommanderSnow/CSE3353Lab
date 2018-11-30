#ifndef DOCUMENTATION_H
#define DOCUMENTATION_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
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
    void saveFile(int selection, double speed, std::vector<int> &bestPath, float bestDist, int size);

    //saves a generation from a genetic search
    void randomGraph(int points);

};

#endif // DOCUMENTATION_H
