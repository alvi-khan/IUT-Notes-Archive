#include<iostream>

using namespace std;

class Calculator
{
private:
    int val;
public:
    int getValue()
    {
        return val;
    }
    void setValue(int value)
    {
        val = value;
    }
    void add(int value)
    {
        val += value;
    }
    void subtract (int value)
    {
        val -= value;
    }
    void multiply (int value)
    {
        val *= value;
    }
    void divideBy (int value)
    {
        val /= value;
    }
    void clearValue()
    {
        val = 0;
    }
    Calculator() : val(0)
    {

    }
    Calculator(int init) : val(init)
    {

    }
};

int main()
{
    Calculator c1;
    Calculator c2(10);  //just proving both initializations worked

    cout<<"Initial Value of c1 = "<<c1.getValue()<<endl;
    cout<<"Initial Value of c2 = "<<c2.getValue()<<endl;

    int newVal;
    cout<<"Set new value for c1: "; //setting new value
    cin>>newVal;
    c1.setValue(newVal);
    cout<<"Calculator Display: "<<c1.getValue()<<endl;

    cout<<"Add: ";
    cin>>newVal;
    c1.add(newVal);
    cout<<"Calculator Display: "<<c1.getValue()<<endl;

    cout<<"Subtract: ";
    cin>>newVal;
    c1.subtract(newVal);
    cout<<"Calculator Display: "<<c1.getValue()<<endl;

    cout<<"Multiply: ";
    cin>>newVal;
    c1.multiply(newVal);
    cout<<"Calculator Display: "<<c1.getValue()<<endl;

    cout<<"Divide by: ";
    cin>>newVal;
    c1.divideBy(newVal);
    cout<<"Calculator Display: "<<c1.getValue()<<endl;

    cout<<"Clearing display..."<<endl;  //proving clear works
    c1.clearValue();
    cout<<"Calculator Display: "<<c1.getValue()<<endl;

}
