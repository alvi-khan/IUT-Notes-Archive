#include<iostream>

using namespace std;

int main()
{
    int n, sum=0, smallest=10000, largest=0;

    cin>>n;

    for (int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;

        sum += temp;

        if (temp<smallest)  smallest = temp;
        if (temp>largest)   largest = temp;
    }

    cout<<sum-largest<<" "<<sum-smallest;
}
