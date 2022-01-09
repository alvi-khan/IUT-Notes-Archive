#include "Square.h"
#include <math.h>

Square::Square(int val)
{
    if (val<0)  side = 0;
    else        side = val;
}

float Square::getDiagonal()
{
    return sqrt(2*side*side);
}

void Square::Setside(int val)
{
    if (val < 0)    side = 0;
    else    side = val;
}

Square Square::operator ++()
{
    side++;
    return side;
}

Square Square::operator ++(int)
{
    return Square (side++);
}

Square Square::operator --()
{
    side--;
    return side;
}

Square Square::operator --(int)
{
    return Square (side--);
}

Square Square::operator +(Square obj)
{
    return Square(side+obj.side);
}

Square Square::operator -(Square obj)
{
    return Square(side-obj.side);
}

bool Square::operator ==(Square obj)
{
    if (getArea() == obj.getArea()) return true;
    else                            return false;
}

bool Square::operator >(Square obj)
{
    if (getArea() > obj.getArea())  return true;
    else                            return false;
}

bool Square::operator <(Square obj)
{
    if (getArea() < obj.getArea())  return true;
    else                            return false;
}
