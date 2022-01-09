// friclass.cpp
// friend classes
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class alpha
{
private:
    int data1;
public:
    alpha() : data1(99) { } //constructor
    friend class beta; //beta is a friend class
};
////////////////////////////////////////////////////////////////
class beta
{
public: //access private alpha data
    void func1(alpha a)
    {
        cout << "\ndata1=" << a.data1;
    }
    void func2(alpha a)
    {
        cout << "\ndata1=" << a.data1;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    alpha a;
    beta b;
    b.func1(a);
    b.func2(a);
    cout << endl;
    return 0;
}
