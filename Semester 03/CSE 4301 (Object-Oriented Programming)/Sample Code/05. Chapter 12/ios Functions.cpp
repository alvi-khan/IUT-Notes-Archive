#include<iostream>
using namespace std;

int main()
{
    int ch = cout.fill(); // Return the fill character (fills unused part of field; default is space)
    cout<<"Default fill value: "<<ch<<endl;
    cout.fill(ch);// Set the fill character

    int p = cout.precision(); //Get the precision (number of digits displayed for floating-point)
    cout<<"Default Precesion:"<<p<<endl;
    cout.precision(11); //Set the precision
    cout<<12.123456789<<endl;

    int w = cout.width(); //Get the current field width (in characters)
    cout<<"Default Width:"<<w<<endl;
    cout.setf(ios::right);
    cout<<"Hi Hello"<<endl;

    cout.width(10);// Set the current field width
    cout.setf(ios::right);
    cout<<"Hi Hello"<<endl;

    cout.width(10);
    cout<<"This is"<<endl;

}
