#include <iostream>
using namespace std;

void display(int node, int begin, int end, int tree[])  // post-order traversal
{
    if (begin == end)   // leaf node
    {
        cout<<tree[node]<<" ";
        return;
    }
    int leftChild = node * 2;   // left child of tree node
    int rightChild = (node * 2) + 1;  // right child of tree node
    int midPoint = (begin + end) / 2;   // mid-point of range
    display(leftChild, begin, midPoint, tree);
    display(rightChild, midPoint + 1, end, tree);
    cout<<tree[node]<<" ";
}

void init(int node, int begin, int end, int tree[], int arr[])
{
    if (begin == end)   // leaf node; insert directly
    {
        tree[node] = arr[begin];
        return;
    }
    int leftChild = node * 2;
    int rightChild = (node * 2) + 1;
    int midPoint = (begin + end) / 2;   // mid-point of range

    // initiate left and right subtrees
    init(leftChild, begin, midPoint, tree, arr);
    init(rightChild, midPoint + 1, end, tree, arr);

    // use initiated values to calculate value of self
    tree[node] = tree[leftChild] + tree[rightChild];
}

void update(int node, int begin, int end, int index, int tree[], int newValue)
{
    if (index > end || index < begin)   return; // out of range
    if (begin == index && end == index)
    {
        tree[node] = newValue;  // node found
        return;
    }
    // node not found; check left and right children
    int leftChild = node * 2;
    int rightChild = (node * 2) + 1;
    int midPoint = (begin + end) / 2;
    update(leftChild, begin, midPoint, index, tree, newValue);  // check left
    update(rightChild, midPoint + 1, end, index, tree, newValue);   // check right

    tree[node] = tree[leftChild] + tree[rightChild];    // update ancestor
}

int sumQuery (int node, int rangeBegin, int rangeEnd, int sumBegin, int sumEnd, int tree[])
{
    if (rangeBegin > sumEnd || rangeEnd < sumBegin) return 0;   // no intersection
    // complete intersection
    if (rangeBegin >= sumBegin && rangeEnd <= sumEnd) return tree[node];
    // partial intersection; return sum of left and right subtrees
    int leftChild = node * 2;
    int rightChild = node * 2 + 1;
    int midPoint = (rangeBegin + rangeEnd) / 2;
    return (sumQuery(leftChild, rangeBegin, midPoint, sumBegin, sumEnd, tree) + sumQuery(rightChild, midPoint + 1, rangeEnd, sumBegin, sumEnd, tree));
}

int main()
{
    int n[3] = {7, 10, 5};
    int m[3] = {(2 * n[0]) - 1, (2 * n[1]) -1, (2 * n[2]) - 1};
    int array1[8] = {0, 4, -9, 3, 7, 1, 0, 2};
    int tree1[14];
    int array2[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tree2[20];
    int array3[6] = {0, -27, 8, 51, 3, -16};
    int tree3[10];


    init (1, 1, n[0], tree1, array1);
    init(1, 1, n[1], tree2, array2);
    init(1, 1, n[2], tree3, array3);

    cout<<"After Initialization (Post-Order):"<<endl;
    cout<<"Tree 1: ";
    display(1, 1, n[0], tree1);
    cout<<"\nTree 2: ";
    display(1, 1, n[1], tree2);
    cout<<"\nTree 3: ";
    display(1, 1, n[2], tree3);

    cout<<"\n\nSum of range 2 - 7 from tree 1: ";
    cout<<sumQuery(1, 1, n[0], 2, 7, tree1);

    cout<<"\nSum of range 3 - 6 from tree 2: ";
    cout<<sumQuery(1, 1, n[1], 3, 6, tree2);

    cout<<"\nSum of range 1 - 5 from tree 3: ";
    cout<<sumQuery(1, 1, n[2], 1, 5, tree3);

    cout<<"\n\nUpdating tree 2 (6 -> 51): ";
    update(1, 1, n[1], 6, tree2, 51);
    cout<<"\nTree 2: ";
    display(1, 1, n[1], tree2);
}
