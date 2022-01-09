// where.cpp
// the this pointer
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class where
{
private:
    char charray[10]; //occupies 10 bytes
    int data;
public:

    void reveal()
    {
        cout << "\nMy object's address is " << this;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    where w1, w2, w3; //make three objects
    //cout<<&w1;
    w1.reveal(); //see where they are
    w2.reveal();
    w3.reveal();

    cout << endl;
    return 0;
}
