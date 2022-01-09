#include "Taka.h"

Taka::Taka(int a, int b, int c, int d, int e)
{
    if (a<0)    one = 0;
    else        one = a;
    if (b<0)    two = 0;
    else        two = b;
    if (c<0)    five = 0;
    else        five = c;
    if (d<0)    ten = 0;
    else        ten = d;
    if (e<0)    twenty = 0;
    else        twenty = e;
}

void Taka::Setone(int val)
{
    if (val<0)  one = 0;
    else one = val;
}

void Taka::Settwo(int val)
{
    if (val<0)  two = 0;
    else two = val;
}

void Taka::Setfive(int val)
{
    if (val<0)  five = 0;
    else five = val;
}

void Taka::Setten(int val)
{
    if (val<0)  ten = 0;
    else ten = val;
}

void Taka::Settwenty(int val)
{
    if (val<0)  twenty = 0;
    else twenty = val;
}

int Taka::getTaka()
{
    return (Getone() + Gettwo()*2 + Getfive()*5 + Getten()*10 + Gettwenty()*20);
}

bool Taka::operator ==(Taka obj)
{
    if (getTaka() == obj.getTaka()) return true;
    else                            return false;
}

bool Taka::operator >(Taka obj)
{
    if (getTaka() > obj.getTaka()) return true;
    else                            return false;
}

bool Taka::operator <(Taka obj)
{
    if (getTaka() < obj.getTaka()) return true;
    else                            return false;
}

Taka Taka::operator +(Taka obj) //adds individual note amounts
{
    Taka temp;
    temp.Setone(Getone()+obj.Getone());
    temp.Settwo(Gettwo()+obj.Gettwo());
    temp.Setfive(Getfive()+obj.Getfive());
    temp.Setten(Getten()+obj.Getten());
    temp.Settwenty(Gettwenty()+obj.Gettwenty());
    return temp;
}

Taka Taka::operator -(Taka obj) //subtracts individual note amounts
{
    Taka temp;

    if (Getone()-obj.Getone() < 0)          temp.Setone(0);
    else                                    temp.Setone(Getone()-obj.Getone());
    if (Gettwo()-obj.Gettwo() < 0)          temp.Settwo(0);
    else                                    temp.Settwo(Gettwo()-obj.Gettwo());
    if (Getfive()-obj.Getfive() < 0)        temp.Setfive(0);
    else                                    temp.Setfive(Getfive()-obj.Getfive());
    if (Getten()-obj.Getten() < 0)          temp.Setten(0);
    else                                    temp.Setten(Getten()-obj.Getten());
    if (Gettwenty()-obj.Gettwenty() < 0)    temp.Setone(0);
    else                                    temp.Settwenty(Gettwenty()-obj.Gettwenty());
    return temp;
}
