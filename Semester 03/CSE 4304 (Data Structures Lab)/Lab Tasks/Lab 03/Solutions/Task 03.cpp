/*
    so everyone must be sorted into groups of 2
    speed of each group is speed of slower member
    so best case is if a slow guy is matched with closest speed
    so just sort entire thing and every two members is a group
    total speed is sum of first member of each group (every 2 people)
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int speeds[n*2];

    for (int i=0; i<n*2; i++)
    {
        cin>>speeds[i];
    }

    sort(speeds, speeds+(n*2));

    int total=0;

    for (int i=0; i<n*2; i+=2)      //speed of every two people
    {
        total += speeds[i];
    }

    cout<<total;
}
