#include<iostream>
using namespace std;

int heapSize = 10;
int A[10 + 1];

void maxHeapify (int A[], int i, int heapSize)
{
    int leftChild = (2*i);
    int rightChild = leftChild + 1;
    int largest = i;

    if (leftChild <= heapSize && A[leftChild] > A[largest])     largest = leftChild;
    if (rightChild <= heapSize && A[rightChild] > A[largest])   largest = rightChild;
    if (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, largest, heapSize);
    }
}

void buildMaxHeap(int A[], int heapSize)
{
    for (int i=heapSize/2; i>0; i--)   maxHeapify(A, i, heapSize);
}

void heapSort(int A[], int heapSize)
{
    int length = heapSize;
    while (length > 0)
    {
        buildMaxHeap(A, length);
        int temp = A[1];
        A[1] = A[length];
        A[length] = temp;
        length--;
    }
}

int extractMax(int A[], int &heapSize)  //removes largest member
{
    if (heapSize > 0)
    {
        int maxValue = A[1];
        A[1] = A[heapSize];         //exchange max member with last member, decrement heapsize and maxheapify again
        heapSize--;
        maxHeapify(A, 1, heapSize);
        return maxValue;
    }
}

void changeKey(int A[], int i, int key, int heapSize)   //changing value
{
    if (key < A[i])         //if key is made smaller, need to max heapify from that node since there may be item below that is larger
    {
        A[i] = key;
        maxHeapify(A, i, heapSize);
    }
    else    //if key is larger, may be larger than parent so need to check with parents
    {
        A[i] = key;
        while (A[i] > A[i/2] && i > 1)
        {
            int temp = A[i];
            A[i] = A[i/2];
            A[i/2] = temp;
            i = i/2;
        }
    }
}

void insertKey(int A[], int key, int &heapSize) //inserting new node
{
    heapSize++;
    A[heapSize] = key;  //add key to end of array
    int i = heapSize;
    while (A[i] > A[i/2] && i > 1)  //check with parents and shift up if larger
    {
        int temp = A[i];
        A[i] = A[i/2];
        A[i/2] = temp;
        i = i/2;
    }
}

int main()
{

}
