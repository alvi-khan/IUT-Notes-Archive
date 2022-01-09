#include "Teacher.h"
#include<iostream>
using namespace std;

void Teacher :: display()
{
    People :: display();
    cout<<"Department: "<<dept<<endl;
    cout<<"Room: "<<room<<endl;
    cout<<"Phone: "<<phone<<endl;
}
