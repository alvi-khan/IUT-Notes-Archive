#include <iostream>
using namespace std;

void init(int node, int begin, int end, int tree[], int arr[])
{
    if (begin == end)   // leaf node; insert directly
    {
        tree[node] = arr[begin];
        return;
    }
    int leftChild = node * 2;
    int rightChild = node * 2 + 1;
    int midPoint = (begin + end) / 2;   // mid-point of range

    // initiate left and right subtrees
    init(leftChild, begin, midPoint, tree, arr);
    init(rightChild, midPoint + 1, end, tree, arr);

    // use initiated values to calculate value of self
    if (tree[leftChild] >= tree[rightChild])    tree[node] = tree[rightChild];
    else    tree[node] = tree[leftChild];
}

int minQuery (int node, int rangeBegin, int rangeEnd, int minBegin, int minEnd, int tree[])
{
    if (rangeBegin > minEnd || rangeEnd < minBegin) return INT16_MAX;   // no intersection
    // complete intersection
    if (rangeBegin >= minBegin && rangeEnd <= minEnd) return tree[node];
    // partial intersection; return min of left and right subtrees
    int leftChild = node * 2;
    int rightChild = node * 2 + 1;
    int midPoint = (rangeBegin + rangeEnd) / 2;
    int leftValue = minQuery(leftChild, rangeBegin, midPoint, minBegin, minEnd, tree);
    int rightValue = minQuery(rightChild, midPoint + 1, rangeEnd, minBegin, minEnd, tree);
    if (leftValue >= rightValue)    return rightValue;
    else                            return leftValue;
}

int main()
{
    int n, q, i, j;
    cin>>n>>q;

    int arr[n+1], tree[2 * n];
    arr[0] = INT16_MAX;
    for (int k=1; k<=n; k++)    cin>>arr[k];

    init(1, 1, n, tree, arr);

    for (int k=0; k<q; k++)
    {
        cin>>i>>j;
        cout<<minQuery(1, 1, n, i, j, tree)<<endl;
    }
}