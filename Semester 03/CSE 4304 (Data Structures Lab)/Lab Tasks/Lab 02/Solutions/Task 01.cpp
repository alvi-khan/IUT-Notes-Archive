#include<iostream>

using namespace std;

int main()
{
    int n, posNums=0;
    long long largest_neg = -1000000000, maxSum = 0;

    cin>>n;

    for (int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;

        if (temp < 0 && temp > largest_neg) largest_neg = temp; //store the largest negative number
        else if (temp >=0)  //store sum of positive number and how many
        {
            maxSum += temp;
            posNums++;
        }

    }

    if (posNums>0)  cout<<maxSum<<" "<<posNums; //print positive number sum if they exist
    else            cout<<largest_neg<<" "<<1;  //or print largest negative number alone
}
