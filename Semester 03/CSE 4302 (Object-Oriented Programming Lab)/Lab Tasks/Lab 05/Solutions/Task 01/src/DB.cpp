#include "DB.h"
#include "DM.h"

DB::DB()
{
    //ctor
}

DB::DB(int a, float b)
{
    feet = a;
    inches = b;
}

DB::~DB()
{
    //dtor
}

void DB::addDist(DM obj)    //converts values and adds
{
    feet = feet + obj.Getmeters()*3;
    inches = inches + obj.Getmeters()*3.37 + obj.Getcentimeters()*0.394;
}

DB DB::addDistRet(DM obj1, DB obj2) //returns the object
{
    feet = obj2.Getfeet() + obj1.Getmeters()*3;
    inches = obj2.Getinches() + obj1.Getmeters()*3.37 + obj1.Getcentimeters()*0.394;
    return *this;
}
