#include<iostream>
using namespace std;

void minHeapify(int arr[], int root, int heapSize)
{
    int largest = root, leftChild = root*2, rightChild = root*2 + 1;

    if (leftChild <= heapSize && arr[leftChild] < arr[largest]) largest = leftChild;
    if (rightChild <= heapSize && arr[rightChild] < arr[largest])   largest = rightChild;

    if (largest != root)
    {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        minHeapify(arr, largest, heapSize);
    }
}

void buildMinHeap(int arr[], int heapSize)
{
    for (int i=heapSize/2; i>0; i--)
    {
        minHeapify(arr, i, heapSize);
    }
}

void change(int arr[], int &heapSize)
{
    if (arr[2]>arr[3])  arr[3] = arr[1] + arr[3]*2; //store new value in position of 2nd least
    else                arr[2] = arr[1] + arr[2]*2;

    arr[1] = arr[heapSize]; //switch places with first least and decrease size
    heapSize--;

    buildMinHeap(arr, heapSize);    //get the smallest to the top again
}

int main()
{
    int arr[100];
    int n, k;
    cin>>n>>k;

    for (int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    buildMinHeap(arr, n);

    int sCount = 0;

    while (arr[1] < k)
    {
        change(arr, n); //keep adding till requirement reached
        sCount++;
        cout<<endl;
    }

    cout<<sCount;


}
