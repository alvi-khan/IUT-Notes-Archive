#include<iostream>
using namespace std;

class Supervisor
{
protected:
    string name;
    float payRate;
    int hoursWorked;
public:
    Supervisor() : name(""), payRate(0.0F), hoursWorked(0) {};

    void setName(string newName) {name = newName;}
    string getName() {return name;}

    void setPayRate(float newPayRate) {payRate = newPayRate;}
    void setHoursWorked(int newHoursWorked)
        {hoursWorked = newHoursWorked;}
    float getPay() {return payRate*hoursWorked;}
};

class Manager : public Supervisor
{
protected:
    float fixedSalary;
public:
    Manager() : fixedSalary(0.0F) {};
    void setFixedSalary (float newFixedSalary)
        {fixedSalary = newFixedSalary;}
    float getPay() {return fixedSalary;}
};

int main()
{
    Supervisor s1;
    s1.setPayRate(1.1);
    s1.setHoursWorked(5);
    cout<<s1.getName()<<endl;
    cout<<s1.getPay()<<endl;
}
