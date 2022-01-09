// counten.cpp
// inheritance with Counter class
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Counter //base class
{
protected: //NOTE: not private
    unsigned int count; //count
public:
    Counter() : count(0) //no-arg constructor
    { }
    Counter(int c) : count(c) //1-arg constructor
    { }
    unsigned int get_count() const //return count
    {
        return count;
    }
    Counter operator ++ () //incr count (prefix)
    {
        return Counter(++count);
    }
    void status()
    {
        cout<<"from base class: "<<count<<endl;
    }
};

////////////////////////////////////////////////////////////////
class CountDn : public Counter //derived class
{
public:
    Counter operator -- () //decr count (prefix)
    {
        return Counter(--count);
    }
    void status()
    {
        cout<<"from DERIVED class: "<<count<<endl;
    }
};
////////////////////////////////////////////////////////////////

int main()
{
    CountDn c1; //c1 of class CountDn
    ++c1;
//    cout << "\nc1=" << c1.get_count(); //display c1
//    ++c1;
//    ++c1;
//    ++c1; //increment c1, 3 times
//    cout << "\nc1=" << c1.get_count(); //display it
//    --c1;
//    --c1; //decrement c1, twice
//    cout << "\nc1=" << c1.get_count(); //display it
//    cout << endl;

    c1.Counter::status();

    return 0;
}
