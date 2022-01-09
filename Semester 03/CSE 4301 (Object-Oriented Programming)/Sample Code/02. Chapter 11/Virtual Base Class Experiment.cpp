// virtbase.cpp
// virtual base classes
#include <iostream>
using namespace std;
class Parent
{
public:
    Parent(int v):basedata(v){}
    int basedata;
};
//class Child1 : public Parent // non virtual base class
class Child1 : virtual public Parent // shares copy of Parent
{ public:Child1():Parent(1){}};
//class Child2 :  public Parent // non virtual base class
class Child2 : virtual public Parent // shares copy of Parent
{ public:Child2():Parent(2){}};

class Grandchild : public Child1, public Child2
{

public:
    Grandchild():Parent(1){}
    int getdata()
    {
        return basedata;    // OK: only one copy of Parent
    }
};

int main()
{
    Child1 A;
    cout<<A.basedata;

    Child2 B;
    cout<<B.basedata;

    Grandchild C;
    cout<<C.getdata();
}

