#include "source.h"

source::source()
{
    name = 0;
    xPos = 0;
    yPos = 0;
    zPos = 0;
}

source::source(int x)
{
    name = x;
    xPos = 0;
    yPos = 0;
    zPos = 0;}

source::source(int x, destination first)
{
    name = x;
    xPos = 0;
    yPos = 0;
    zPos = 0;
    destinations.emplace_back(first);
}

source::source(source& rhs)
{
    this->name = rhs.getName();
    this->xPos = rhs.getxPos();
    this->yPos = rhs.getyPos();
    this->zPos = rhs.getzPos();
    this->destinations = rhs.getDestinations();
}


//constructs a destination (with only a name) at the end of the list
void source::addDestination(int x)
{
    destination newDestination;
    newDestination.setName(x);

    destinations.emplace_back(newDestination);
}

//constructs a destination (with a name and cost) at the end of the list
void source::addDestination(int x, int cost)
{
    destination newDestination(x, cost);


    destinations.emplace_back(newDestination);
}

void source::display()
{
    std::cout << "My name is " << name <<std::endl;
}

//returns the source name/number
int& source::getName()
{
    return name;
}

void source::setName(int x)
{
    name = x;
}

int& source::getxPos()
{
    return xPos;
}
void source::setxPos(int x)
{
    xPos = x;
}

int& source::getyPos()
{
    return yPos;
}
void source::setyPos(int y)
{
    yPos = y;
}

int& source::getzPos()
{
    return zPos;
}
void source::setzPos(int z)
{
    zPos = z;
}
//returns the list of destinations
std::list<destination> &source::getDestinations()
{
    return destinations;
}

destination& source::findNode(int x)
{
    destination compare(x);
    std::list<destination>::iterator iter = destinations.begin();
    int listSize = destinations.size();


    for(int i=0; i<listSize; i++)
    {
        //std::cout << "iter = " << iter->getName() <<std::endl;
        if(x == *iter)
        {    return *iter;    }

        iter++;
    }

    std::cout << "Could not find node, returning last node instead" <<std::endl;

    return *iter;
}
/*
source& source::operator =(source &rhs)
{
    if(this == &rhs)
    {
        return *this;
    }

    this->name = rhs.getName();
    this->xPos = rhs.getxPos();
    this->yPos = rhs.getyPos();
    this->zPos = rhs.getzPos();
    this->destinations = rhs.getDestinations();

    return *this;
}*/

bool operator==(source& lhs, source& rhs)
{
    if(lhs.getName() == rhs.getName())
    {   return true;   }

    return false;
}

bool operator==(int lhs, source& rhs)
{
    if(lhs == rhs.getName())
    {   return true;   }

    return false;
}

source::~source()
{

}
