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

void paranoidQuickSort(long long low, long long high)
{
    long long minPoint = low + (high - low) / 4, maxPoint = high - (high - low) / 4;
    // 1/4th and 3/4th of range respectively

    long long pivotInd;
    if(low < high)                                  // if there are at least 2 elements
    {
        do                                          // find new random pivots while not within range
        {
            swap(arr[low], arr[low + rand() % (high - low)]);
            // low will be pivot so set random index to low
            pivotInd = partition(low, high);        // find pivotInd
        } while (pivotInd < minPoint || pivotInd > maxPoint);

        paranoidQuickSort(low, pivotInd-1);           // sort left half
        paranoidQuickSort(pivotInd + 1, high);        // sort right half
    }
}

int main()
{
    srand(unsigned(time(NULL)));
}