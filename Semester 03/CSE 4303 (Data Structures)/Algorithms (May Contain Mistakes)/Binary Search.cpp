#include<iostream>
using namespace std;

int binarySearch (int arr[], int search, int low, int up)
{
    if (up >= low)
    {
        int mid = low + (up - low)/2;
        if (search == arr[mid])     return mid;
        else if (search > arr[mid]) return binarySearch (arr, search, mid+1, up);
        else if (search < arr[mid]) return binarySearch (arr, search, low, mid-1);
    }
    else return -1;
}

int main()
{

}

