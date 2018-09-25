#ifndef SOURCE_H
#define SOURCE_H

#include <list>
#include <iostream>

#include "destination.h"


class source
{
private:

    //the name of the node
    int name;

    //the x,y,z position of the node
    int xPos;
    int yPos;
    int zPos;

    //the list of destinations the node connects to
    std::list<destination> destinations;

public:

    source();
    source(int);
    source(int x, destination first);
    source(source& rhs);

    //constructs a destination at the end of the list
    void addDestination(int);
    void addDestination(int, int);

    //displays the source and all its relations
    void display();

    //getter and setter for name
    int& getName();
    void setName(int);

    //getter and setter for pos
    int& getxPos();
    void setxPos(int);
    int& getyPos();
    void setyPos(int);
    int& getzPos();
    void setzPos(int);

    //returns the list of destinations
    std::list<destination> &getDestinations();

    //returns the node with the found location
    destination& findNode(int);

    //source& operator=(source &);

    //overloading the == operator to work with the find function in list classes
    friend bool operator==(source& lhs,  source& rhs);
    friend bool operator==(int lhs,  source& rhs);

    ~source();

};

#endif // SOURCE_H
