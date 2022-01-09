#include<iostream>

using namespace std;

float ctof(float c)
{
    float f=(c*9/5)+32;
    return f;
}

float ftoc(float f)
{
    float c=(f-32)*5/9;
    return c;
}

int getInput()
{
    int choice;
    float input;
    cout<<"Do you want to convert input to 1. Celsius or to 2. Fahrenheit?\n";
    cin>>choice;

    if (choice == 1)
    {
        cout<<"Enter input: ";
        cin>>input;
        cout<<ftoc(input);
        return 1;
    }
    else if (choice == 2)
    {
        cout<<"Enter input: ";
        cin>>input;
        cout<<ctof(input);
        return 1;
    }
    else
    {
        cout<<"Invalid input"<<endl;
        return 0;
    }
}

int main()
{
    int a = 0;
    while (a != 1)  a = getInput();
}
