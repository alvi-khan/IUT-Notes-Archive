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

void extractKey(int arr[], int &length)
{
    arr[1] = arr[length];   //switch places, decreases size, and build heap
    length--;
    buildMinHeap(arr, length);
}

void insertKey(int arr[], int input, int &length)
{
    length++;
    arr[length] = input;    //increase size, add value and build heap
    buildMinHeap(arr, length);
}

void decreaseKey(int arr[], int index, int newKey)
{
    arr[index] = newKey;        //change value and keep switching with parents
    while (index != 1)
    {
        int parent = index/2;
        if (arr[parent] > arr[index])
        {
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;
            index = parent;
        }
        else    break;
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

    buildMinHeap(arr, length);

    cout<<"Min Heap:"<<endl;

    for (int i=1; i<=length; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int n = -1;

    while (n!=5)
    {
        cout<<"Choose a task:\n1. Get minimum priority member from heap.\n2. Extract minimum priority member from heap.\n3. Insert member in heap.\n4. Decrease value of existing member.\n5. Exit."<<endl;

        cin>>n;

        if (n == 1) cout<<"Minimum Priority Member: "<<arr[1]<<endl;
        else if (n == 2)
        {
            cout<<"Minimum priority member extracted.\n\nNew Heap: ";
            extractKey(arr, length);
            for (int i=1; i<=length; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        else if (n == 3)
        {
            int input;
            cout<<"Enter member to insert: ";
            cin>>input;

            insertKey(arr, input, length);

            cout<<"New array: ";
            for (int i=1; i<=length; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else if (n == 4)
        {
            cout<<"Current Heap: ";
            for (int i=1; i<=length; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            int index, newKey;
            cout<<"Enter index of key to change: ";
            cin>>index;
            cout<<"Enter new value: ";
            cin>>newKey;
            decreaseKey(arr, index, newKey);
            cout<<"New Heap: ";
            for (int i=1; i<=length; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else if (n == 5)    exit(1);
    }
}

