#include<iostream>
using namespace std;

void maxHeapify(int arr[], int root, int heapSize)
{
    int largest = root, leftChild = root*2, rightChild = root*2 + 1;

    if (leftChild <= heapSize && arr[leftChild] > arr[largest]) largest = leftChild;
    if (rightChild <= heapSize && arr[rightChild] > arr[largest])   largest = rightChild;

    if (largest != root)
    {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest, heapSize);
    }
}

void buildMaxHeap(int arr[], int heapSize)
{
    for (int i=heapSize/2; i>0; i--)
    {
        maxHeapify(arr, i, heapSize);
    }
}

void heapSort(int arr[], int length)
{


    int heapSize = length;

    while (heapSize > 0)
    {
        buildMaxHeap(arr, heapSize);
        int temp = arr[1];
        arr[1] = arr[heapSize];
        arr[heapSize] = temp;
        heapSize--;
    }
}

int main()
{
    int arr[100];

    cout<<"Enter number of inputs: ";

    int length;
    cin>>length;

    cout<<"Enter inputs: ";

    for (int i=1; i<=length; i++)   cin>>arr[i];

    heapSort(arr, length);

    cout<<"Sorted array:"<<endl;

    for (int i=1; i<=length; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
