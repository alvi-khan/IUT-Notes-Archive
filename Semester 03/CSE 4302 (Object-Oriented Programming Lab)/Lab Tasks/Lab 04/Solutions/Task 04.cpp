#include<iostream>
using namespace std;

class SavingsAccount
{
    static int objCount;
    static float annualInterestRate;
    float savingsBalance;

public:
    void calculateMonthlyInterest()
    {
        savingsBalance += (savingsBalance*annualInterestRate)/12.0;
    }
    void displayBalance()
    {
        cout<<savingsBalance<<endl;
    }
    static void modifyInterestRate(float newValue)
    {
        annualInterestRate = newValue;
    }
    SavingsAccount(float value)
    {
        savingsBalance = value;
        objCount++;
    }
    void displayObjCount()
    {
        cout<<objCount<<endl;
    }
};

float SavingsAccount :: annualInterestRate = 0;
int SavingsAccount :: objCount = 0;

int main()
{
    SavingsAccount s1(2000.00);
    s1.displayObjCount();
    SavingsAccount s2(3000.00);
    s1.displayObjCount();
    s1.displayBalance();
    s2.displayBalance();
    s1.modifyInterestRate(3.0);
    s1.calculateMonthlyInterest();
    s2.calculateMonthlyInterest();
    s1.displayBalance();
    s2.displayBalance();
    s2.modifyInterestRate(4.0);
    s1.calculateMonthlyInterest();
    s2.calculateMonthlyInterest();
    s1.displayBalance();
    s2.displayBalance();
}
