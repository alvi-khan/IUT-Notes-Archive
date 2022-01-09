#include "Coord.h"
#include<math.h>

Coord::Coord()
{
    //ctor
}

Coord::Coord(double a, double b)
{
    x = a;
    j = b;
}

Coord::~Coord()
{
    //dtor
}

void Coord::setCoordInPolar(double distance, double angleInDegree)  //polar to cartesian
{
    x = distance * cos(angleInDegree);
    j = distance * sin(angleInDegree);
}

int Coord::getQuadrant()
{
    if (x>0 && j>0) return 1;
    else if (x<0 && j>0)    return 2;
    else if (x<0 && j<0)    return 3;
    else if (x>0 && j<0)    return 4;
}

double Coord::distance(const Coord other)
{
    return sqrt(other.x*other.x + other.j*other.j);
}
