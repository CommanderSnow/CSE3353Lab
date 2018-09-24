#ifndef GRAPHDOCUMENTATION_H
#define GRAPHDOCUMENTATION_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

#include "source.h"
#include "destination.h"

using std::string;


class graphDocumentation
{
private:

    string argv[20];
    int argf;
    int argc;

    std::list<source> graph;

public:

    graphDocumentation();

    //reads and constructs the list
    void buildGraph();

    //finds a match within the list
    source& findNode(source);

    //returns the graph
    std::list<source>& getGraph();


};

#endif // GRAQPHDOCUMENTATION_H
