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
    int rightChild = node * 2 + 1;
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
    int n, q, opt, i, j, v;
    cin>>n>>q;
    int arr[n+1], tree[(2*n)];

    for (int k=1; k<=n; k++)    cin>>arr[k];
    init(1, 1, n, tree, arr);

    for (int k=0; k<q; k++)
    {
        cin>>opt;

        if (opt == 1)
        {
            cin>>i;
            cout<<arr[i+1]<<endl;
            arr[i+1] = 0;
            update(1, 1, n, i+1, tree, 0);
        }
        else if (opt == 2)
        {
            cin>>i>>v;
            update(1, 1, n, i+1, tree, arr[i+1] + v);
            arr[i+1] += v;
        }
        else if (opt == 3)
        {
            cin>>i>>j;
            cout<<sumQuery(1, 1, n, i+1, j+1, tree)<<endl;
        }
    }
}
