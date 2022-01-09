#include<iostream>
using namespace std;

void insertionSort (int arr[], int len)
{
    for (int i=1; i<len; i++)
    {
        int key = arr[i];
        int j = i;
        while (arr[j-1] > key && j > 0) //starting from the key's position, shift all larger items back
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;   //put key just behind item that was not larger
    }
}

int main()
{

}
