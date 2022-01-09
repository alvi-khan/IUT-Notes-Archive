#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

long long arr1[1000000];
long long arr2[1000000];

void insertionSort (long long arr[], long long n)
{
    cout<<"Insertion Sort Running..."<<endl;
    long long i, j, key;
    clock_t start, finish;
    long long comparisons = 0;

    start = clock();
    for (i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
            comparisons++;
        }
        arr[j+1] = key;
        comparisons++;
    }
    finish = clock();

    cout<<"Time Needed: "<<((double) (finish-start))/CLOCKS_PER_SEC<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
}

void bubbleSort(long long arr[], long long n)
{
    cout<<"Bubble Sort running..."<<endl;
    long long i, j;
    clock_t start, finish;
    long long comparisons = 0;

    start = clock();
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            comparisons++;
        }
    }
    finish = clock();

    cout<<"Time Needed: "<<((double) (finish-start))/CLOCKS_PER_SEC<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
}

int main()
{
    long long n;
    cout<<"Give size of Input: ";
    cin>>n;

    cout<<"Generating random input... ";
    for (long long i=0; i<n; i++)
    {
        arr1[i] = rand();
        arr2[i] = arr1[i];
    }
    cout<<"Done."<<endl;

    insertionSort(arr1, n);

    bubbleSort(arr2, n);
}
