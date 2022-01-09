
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Shape
{
public:
    Shape()
    { }
    virtual double area()=0;
    virtual double perimeter()=0;
};

class Circle:public Shape
{
    double radius;
public:
    Circle():radius(0)
    {}
    Circle(double val):radius(0)
    {setRadius(val);}
    void setRadius(double val){if(val>=0)radius=val;}
    double area(){return 2*3.14*radius*radius;}
    double perimeter(){return 2*3.14*radius;}
};

class Rectangle:public shape
{
    double length,width;
public:
    Rectangle():length(0),width(0)
    { }
    Rectangle(double l,double w):length(0),width(0)
    { setLength(l);setWidth(w);}
    void setLength(double val){if(val>=0)length=val;}
    void setWidth(double val){if(val>=0)width=val;}
    double area(){return length*width;}
    double rec_perimeter(){return 2*(length+width);}
};

int main()
{

    Circle c1(5);
    Rectangle r(2,5);

    cout<<c1.area()<<endl;
    cout<<r.area()<<endl;
    return 0;
}
