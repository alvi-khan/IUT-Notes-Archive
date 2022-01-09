#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i=0; i<n-1; i++)   //for every loop, find smallest item and put in ith position
    {
        int min_idx = i;
        for (int j=i+1; j<n; j++)   //finding item smaller than key
          if (arr[j] < arr[min_idx])    min_idx = j;
        int temp = arr[min_idx];    //exchange smallest item with key
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{

}

