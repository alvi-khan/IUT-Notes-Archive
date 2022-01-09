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
};

////////////////////////////////////////////////////////////////
class CountDn : public Counter //derived class
{
public:
    Counter operator -- () //decr count (prefix)
    {
        return Counter(--count);
    }
};
////////////////////////////////////////////////////////////////

int main()
{
    CountDn c1; //c1 of class CountDn

    cout << "\nc1=" << c1.get_count(); //display c1
    Counter c= ++c1;
    ++c1;
    ++c1; //increment c1, 3 times
    cout << "\nc1=" << c1.get_count(); //display it
    --c1;
    --c1; //decrement c1, twice
    cout << "\nc1=" << c1.get_count(); //display it
    cout << endl;


    return 0;
}
