#include "destination.h"


destination::destination()
{
    name = 0;
    edge = 0;
}

destination::destination(int x)
{
    name = x;
}

destination::destination(const destination &rhs)
{
    this->name = rhs.getName();
    this->edge = rhs.getEdge();
}

destination::destination(int x, int cost)
{
    name = x;
    edge = cost;
}

void destination::setName(int x)
{
    name = x;
}

const int& destination::getName() const
{
    return name;
}

void destination::setEdge(int cost)
{
    edge = cost;
}

const int &destination::getEdge() const
{
    return edge;
}

bool operator==(destination& lhs, destination& rhs)
{
    if(lhs.getName() == rhs.getName())
    {   return true;   }

    return false;
}

bool operator==(int lhs, destination& rhs)
{
    if(lhs == rhs.getName())
    {   return true;   }

    return false;
}
