#include "point.h"

point::point()
{
    name = 0;
    x = 0;
    y = 0;
    z = 0;
}

point::point(int Name, float X, float Y, float Z)
{
    name = Name;
    x = X;
    y = Y;
    z = Z;
}

point::point(const point& rhs)
{
    this->name = rhs.name;
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
}

const int& point::getCName() const
{
    return name;
}

int& point::getName()
{
    return name;
}

float& point::getX()
{
    return x;
}
float& point::getY()
{
    return y;
}
float& point::getZ()
{
    return z;
}

void point::getLocation(float* &location)
{
    location[0] = x;
    location[1] = y;
    location[2] = z;
}

void point::setName(int Name)
{
    name = Name;
}

void point::setX(float X)
{
    x = X;
}
void point::setY(float Y)
{
    y = Y;
}
void point::setZ(float Z)
{
    z = Z;
}

bool operator <(point const &lhs, point &rhs)
{
    if(lhs.getCName() < rhs.getCName())
    {   return true;    }

    return false;
}

bool operator==(point& lhs, point& rhs)
{
    if(lhs.getName() == rhs.getName())
    {   return true;   }

    return false;
}
