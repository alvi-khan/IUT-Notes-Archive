#include <iostream>
using namespace std;

void display(int node, int begin, int end, int tree[], int treeLength)  // post-order traversal
{
    if (begin == end)   // leaf node; display and return
    {
        cout<<tree[node]<<" ";
        return;
    }
    int leftChild = node * 2;           // left child of tree node
    int rightChild = (node * 2) + 1;    // right child of tree node
    int midPoint = (begin + end) / 2;   // mid-point of range

    display(leftChild, begin, midPoint, tree, treeLength);
    display(rightChild, midPoint + 1, end, tree, treeLength);

    cout<<tree[node]<<" ";
}

void init(int node, int begin, int end, int tree[], int arr[])
{
    if (begin == end)   // leaf node; insert directly
    {
        tree[node] = arr[begin];
        return;
    }
    int leftChild = node * 2;           // left child of tree node
    int rightChild = (node * 2) + 1;    // right child of tree node
    int midPoint = (begin + end) / 2;   // mid-point of range

    init(leftChild, begin, midPoint, tree, arr);    // initialize children
    init(rightChild, midPoint + 1, end, tree, arr);

    tree[node] = tree[leftChild] + tree[rightChild];    // store sum
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
    if (rangeBegin >= sumBegin && rangeEnd <= sumEnd) return tree[node];    // complete intersection
    // partial intersection; return sum of left and right subtrees
    int leftChild = node * 2;
    int rightChild = (node * 2) + 1;
    int midPoint = (rangeBegin + rangeEnd) / 2;
    return (sumQuery(leftChild, rangeBegin, midPoint, sumBegin, sumEnd, tree) + sumQuery(rightChild, midPoint + 1, rangeEnd, sumBegin, sumEnd, tree));
}

int main()
{
    int n=7, m=(4*n), arr[n+1], tree[m+1];
    for (int i=1; i<=n; i++)    cin>>arr[i]; // taking input
    init(1, 1, n, tree, arr);   // initializing segment tree

    display(1, 1, n, tree, m);
    cout<<endl;

    cout<<sumQuery(1, 1, n, 1, 5, tree)<<endl;

    update(1, 1, n, 3, tree, 43);

    display(1, 1, n, tree, m);
    cout<<endl;

    cout<<sumQuery(1, 1, n, 1, 5, tree)<<endl;
}