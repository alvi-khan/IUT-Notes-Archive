#include<iostream>
using namespace std;

int heapSize = 10;
int A[10 + 1];

void maxHeapify (int A[], int i, int heapSize)  //create a max heap from a node
{
    int leftChild = (2*i);
    int rightChild = leftChild + 1;
    int largest = i;

    if (leftChild <= heapSize && A[leftChild] > A[largest])     largest = leftChild;
    if (rightChild <= heapSize && A[rightChild] > A[largest])   largest = rightChild;
    if (largest != i)                   //detect largest value, make exchange and recursively call maxHeapify
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, largest, heapSize);
    }
}

void buildMaxHeap(int A[], int heapSize)    //max heap every parent node from bottom up
{
    for (int i=heapSize/2; i>0; i--)   maxHeapify(A, i, heapSize);
}

void heapSort(int A[], int heapSize)
{
    int length = heapSize;
    buildMaxHeap(A, length);    //create initial max heap
    while (length > 0)
    {
        maxHeapify(A, 1, length);   //max heapify just the root since only that changes
        int temp = A[1];            //exchange root with last value, and decrement length of heap, kicking out the last root from the heap but keeping it in the array
        A[1] = A[length];
        A[length] = temp;
        length--;
    }
}

int main()
{

}
