#include <iostream>
#include "Taka.h"

using namespace std;

int main()
{
    Taka billA, billB(1, 2, 3, 4, 5);
    cout<<"billA initial total: "<<billA.getTaka()<<endl;
    cout<<"billB initial total: "<<billB.getTaka()<<endl;
    billA.Setone(1);
    billA.Settwo(2);
    billA.Setfive(3);
    billA.Setten(4);
    billA.Settwenty(5);
    cout<<"Comparing billA and billB totals... ";
    if (billA == billB)     cout<<"Equal."<<endl;
    else if (billA > billB) cout<<"billA more than billB."<<endl;
    else if (billA < billB) cout<<"billA less than billB."<<endl;

    Taka billC = billA+billB;
    cout<<"billC initial total: "<<billC.getTaka()<<endl;

    Taka billD = billA - billB;
    cout<<"billD initial total: "<<billD.getTaka()<<endl;
}
