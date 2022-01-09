#include "Student.h"
#include<iostream>
using namespace std;

void Student :: display()
{
    People :: display();
    cout<<"Student ID: "<<sid<<endl;
    cout<<"CGPA: "<<cgpa<<endl;
    cout<<"Department: "<<dept<<endl;
}
