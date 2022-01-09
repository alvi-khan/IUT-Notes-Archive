#include<iostream>

using namespace std;

class Flight
{
private:
    int flightNum;
    string destination;
    float distance;
    float maxFuel;
    float fuel;
    bool valid;

    void calFuel()      //calculates fuel needed for journey
    {
        if (distance <= 1000)       fuel = 500;
        else if (distance <= 2000)  fuel = 1100;
        else                        fuel = 2200;

        if (fuel > maxFuel) valid = 0;              //if fuel needed exceeds capacity
        else                valid = 1;
    }

public:
    void feedInfo(int fnumb, string dest, float dist, float fuelCap)
    {
        flightNum = fnumb;
        destination = dest;
        distance = dist;
        maxFuel = fuelCap;
        calFuel();
    }

    void showInfo()
    {
        cout<<"Flight Number:\t"<<flightNum<<endl;
        cout<<"Destination:\t"<<destination<<endl;
        cout<<"Distance:\t"<<distance<<endl;
        cout<<"Fuel Required:\t"<<fuel<<endl;
        cout<<"Fuel Capacity:\t"<<maxFuel<<endl;

        if (valid == 0) cout<<"Invalid data.\nFuel required exceeds capacity."<<endl;
        else            cout<<"Flight is possible."<<endl;
    }
};

int main()
{
    int flightNum;
    string destination;
    float distance;
    float fuelCap;

    cout<<"Please enter flight data:\n\nFlight Number: ";
    cin>>flightNum;
    cout<<endl<<"Destination: ";
    cin>>destination;
    cout<<endl<<"Distance: ";
    cin>>distance;
    cout<<endl<<"Flight Fuel Capacity: ";
    cin>>fuelCap;
    cout<<endl<<endl;

    Flight c1;

    c1.feedInfo(flightNum, destination, distance, fuelCap);

    c1.showInfo();
}
