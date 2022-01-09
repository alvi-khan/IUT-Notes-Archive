#include<iostream>

using namespace std;

int binSearch(int arr[], int start, int length, int target)
{
    int mid = (start+length)/2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target && arr[mid+1] > target)  return mid;
    else if (arr[mid]>target)   return binSearch(arr, start, mid-1, target);
    else if (arr[mid]<target)   return binSearch(arr, mid+1, length, target);
}

int sum(int arr[], int endPos)
{
    int sum=0;
    for (int i=0; i<endPos; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int main()
{
    int sold, rounds;

    cin>>sold;

    int soldPow[sold];

    for (int i=0; i<sold; i++)
    {
        cin>>soldPow[i];
    }

    cin>>rounds;

    for (int i=0; i<rounds; i++)
    {
        int alPow;
        cin>>alPow;

        if (alPow>=soldPow[0] && alPow<=soldPow[sold-1])
        {
            int soldBeat = binSearch(soldPow, 0, sold-1, alPow)+1;
            cout<<soldBeat<<" "<<sum(soldPow, soldBeat)<<endl;
        }

        else if (alPow>soldPow[sold-1])
        {
            cout<<sold<<" "<<sum(soldPow, sold)<<endl;
        }

        else    cout<<0<<" "<<0<<endl;
    }
}
