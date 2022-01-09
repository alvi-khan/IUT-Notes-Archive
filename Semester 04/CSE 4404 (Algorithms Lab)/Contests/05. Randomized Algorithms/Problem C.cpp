// Test Code Here: https://www.e-olymp.com/en/problems/2321
#include<bits/stdc++.h>
using namespace std;

long long arr[1005];

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

        quickSort(low, pivotInd-1);           // sort left half
        quickSort(pivotInd + 1, high);        // sort right half
    }
}

int main()
{
    srand(unsigned(time(NULL)));
    long long n;
    scanf("%lld", &n);

    for (long long i=0; i<n; i++)   scanf("%lld", &arr[i]);

    quickSort(0, n - 1);

    for (long long i=0; i<n; i++)
    {
        printf("%lld", arr[i]);
        if (i != n - 1) printf(" ");
        else            printf("\n");
    }
}