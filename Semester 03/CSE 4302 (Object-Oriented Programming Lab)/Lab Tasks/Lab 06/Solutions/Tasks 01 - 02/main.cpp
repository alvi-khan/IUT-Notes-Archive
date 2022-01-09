#include <iostream>
#include "Square.h"

using namespace std;

int main()
{

    cout<<"Task 1:"<<endl;
    Square s0, s1, s2(10);
    s0.Setside(-1);
    s1.Setside(5);
    cout<<"s1 side value: "<<s1.Getside()<<endl;
    cout<<"s2 side value: "<<s2.Getside()<<endl;
    cout<<"s1 perimeter: "<<s1.getPerimeter()<<endl;
    cout<<"s1 diagonal: "<<s1.getDiagonal()<<endl;
    cout<<"s1 area: "<<s1.getArea()<<endl;



    cout<<endl<<"Task 2:"<<endl;


    Square s1,s2(5); // length of side of s1 is 0 unit
    cout<<"Intializing s1 and s2"<<endl;
    cout<<"s1 value: "<<s1.Getside()<<endl;
    cout<<"s2 value: "<<s2.Getside()<<endl<<endl;
    Square s3 = ++s1; // after this s3 has 1 unit side & s1 has 1 unit side
    cout<<"s3 = ++s1"<<endl;
    cout<<"s1 value: "<<s1.Getside()<<endl;
    cout<<"s3 value: "<<s3.Getside()<<endl<<endl;
    Square s4 = s1++; // after this s4 has 1 unit side & s1 has 2 unit side
    cout<<"s4 = s1++"<<endl;
    cout<<"s1 value: "<<s1.Getside()<<endl;
    cout<<"s4 value: "<<s4.Getside()<<endl<<endl;
    s3 = --s2; // after this s3 has 4 unit side & s2 has 4 unit side
    cout<<"s3 = --s2"<<endl;
    cout<<"s2 value: "<<s2.Getside()<<endl;
    cout<<"s3 value: "<<s3.Getside()<<endl<<endl;
    s4 = s2--; // after this s4 has 4 unit side & s2 has 3 unit side
    cout<<"s4 = s2--"<<endl;
    cout<<"s2 value: "<<s2.Getside()<<endl;
    cout<<"s4 value: "<<s4.Getside()<<endl<<endl;
    s4 = s1+s2; // after this s4 has 5 unit side & s1 and s2 remains unchanged
    cout<<"s4 = s1+s2"<<endl;
    cout<<"s1 value: "<<s1.Getside()<<endl;
    cout<<"s2 value: "<<s2.Getside()<<endl;
    cout<<"s4 value: "<<s4.Getside()<<endl<<endl;
    s3 = s4-s2; // after this s3 has 1 unit side & s4 and s2 remains unchanged
    cout<<"s3 = s4-s2"<<endl;
    cout<<"s2 value: "<<s2.Getside()<<endl;
    cout<<"s3 value: "<<s3.Getside()<<endl;
    cout<<"s4 value: "<<s4.Getside()<<endl<<endl;
    // == returns true if area is on both side same else false
    cout<<"Comparing s4 with (s1+s2)"<<endl;
    //s4.Setside(10);
    if(s4 == s1+s2)
    cout<<"Area is same";
    // == returns true if LHS has bigger area else false
    else if(s4 > s1+s2)
    cout<<"LHS has bigger area";
        // == returns true if LHS has smaller area else false
    else if(s4 < s1+s2)
    cout<<"RHS has bigger area";
    return 0;



}
