#include<bits/stdc++.h>
using namespace std;

long long arr[1000];

long long partition(long long low, long long high)          // find pivot index
{
    long long pivot = low, i = low, j = high;

    while (i < j)                                           // while valid
    {
        while (arr[i] <= arr[pivot] && i < high)    i++;    // move i right
        while (arr[j] > arr[pivot])                 j--;    // move j left
        if (i < j)      swap(arr[i], arr[j]);       // in case j is pivotInd
    }
    swap(arr[pivot], arr[j]);                        // j is pivotInd
    return j;                                               // return pivotInd
}

void quickSort(long long low, long long high)
{
    if(low < high)                                          // if there are at least 2 elements
    {
        long long pivotInd = partition(low, high);          // find pivotInd
        quickSort(low, pivotInd-1);                   // sort left half
        quickSort(pivotInd + 1, high);                // sort right half
    }
}

int main()
{
    
}