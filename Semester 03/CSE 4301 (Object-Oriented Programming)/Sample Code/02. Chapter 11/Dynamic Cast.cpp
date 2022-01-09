//dyncast1.cpp
//dynamic cast used to test type of object
//RTTI must be enabled in compiler
#include <iostream>
#include <typeinfo> //for dynamic_cast
using namespace std;
////////////////////////////////////////////////////////////////
class Base
{
    virtual void vertFunc() //needed for dynamic cast
    { }
};

class Derv1 : public Base
{ };
class Derv2 : public Base
{ };
////////////////////////////////////////////////////////////////
//checks if pUnknown points to a Derv1
bool isDerv1(Base* pUnknown) //unknown subclass of Base
{
    Derv1* pDerv1;
    if( pDerv1 = dynamic_cast<Derv1*>(pUnknown) )
        return true;
    else
        return false;
}
//--------------------------------------------------------------
int main()
{
    Derv1* d1 = new Derv1;
    Derv2* d2 = new Derv2;
    if( isDerv1(d1) )
        cout << "d1 is a member of the Derv1 class\n";
    else
        cout << "d1 is not a member of the Derv1 class\n";
    if( isDerv1(d2) )
        cout << "d2 is a member of the Derv1 class\n";
    else
        cout << "d2 is not a member of the Derv1 class\n";
    return 0;
}
