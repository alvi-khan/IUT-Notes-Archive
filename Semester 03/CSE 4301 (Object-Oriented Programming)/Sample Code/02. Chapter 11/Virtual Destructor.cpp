//vertdest.cpp
//tests non-virtual and virtual destructors
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Base
{public:
    //~Base() //non-virtual destructor
    virtual ~Base() //virtual destructor
    {cout << "Base destroyed\n";}
};
////////////////////////////////////////////////////////////////
class Derv : public Base
{public:
    ~Derv()
    {cout << "Derv destroyed\n";}
};
////////////////////////////////////////////////////////////////
int main()
{
    Base* pBase = new Derv;
    delete pBase;
    return 0;
}
