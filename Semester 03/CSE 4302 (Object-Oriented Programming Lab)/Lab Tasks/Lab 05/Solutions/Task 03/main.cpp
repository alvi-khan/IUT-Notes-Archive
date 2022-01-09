#include <iostream>
#include<Coord.h>

using namespace std;

int main()
{
    Coord c1;
    Coord c2(5.0, -2.0);
    Coord c3;
    c3.setCoordInPolar(5.0, 30);

    cout<<c2.getQuadrant()<<endl;
    cout<<c2.distance(c3)<<endl;
    return 0;
}
