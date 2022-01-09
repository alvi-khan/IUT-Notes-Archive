#include<iostream>
using namespace std;

class Flight
{
    static int totalPlanes;
    int flightNum;
    int capacity;
    string destination;
    int fuel;

public:
    int getTotalPlanes() {return totalPlanes;}

    void setFlightNum(int a) {flightNum = a;}
    int getFlightNum() {return flightNum;}

    void setCapacity(int a) {capacity = a;}
    int getCapacity() {return capacity;}

    void setDestination(string a) {destination = a;}
    string getDestination() {return destination;}

    void setDistance(int a)
    {
        if (a/4 > 2000) cout<<"\nWarning! Fuel required exceeds capacity! Distance not set!"<<endl;
        else    fuel = a/4;
    }

    int getFuelRequired() {return fuel;}

    Flight() : flightNum(totalPlanes+1), capacity(0), destination(""), fuel(0) {totalPlanes++;}
};

int Flight :: totalPlanes(0);

class Airline
{
    Flight f[10];
public:
    void setInfo(int a)
    {
        if (a>10)   cout<<"No such flight exists!"<<endl;
        else
        {
            int tempInt;
            string tempString;
            cout<<"\nEnter Passenger Capacity: ";
            cin>>tempInt;
            f[a-1].setCapacity(tempInt);
            cout<<"\nEnter Destination: ";
            cin>>tempString;
            f[a-1].setDestination(tempString);
            cout<<"\nEnter Distance from Dhaka: ";
            cin>>tempInt;
            f[a-1].setDistance(tempInt);
        }
    }

    void showInfo()
    {
        for (int i=0; i<f[0].getTotalPlanes(); i++)
        {
            cout<<"\nFlight Number: "<<f[i].getFlightNum()<<"\nPassenger Capacity: "<<f[i].getCapacity()<<"\nDestination: "<<f[i].getDestination()<<"\nFuel Required: "<<f[i].getFuelRequired()<<endl;
        }
    }
};

int main()
{
    Airline a;

    a.setInfo(1);
    a.showInfo();
}
