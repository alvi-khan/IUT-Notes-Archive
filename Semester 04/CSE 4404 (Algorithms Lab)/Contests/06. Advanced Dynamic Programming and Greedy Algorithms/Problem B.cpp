#include<bits/stdc++.h>
using namespace std;

const int maxSize = 255;
int frequency[maxSize] = {0};
int weight[maxSize] = {0};
int memo[maxSize][maxSize];

int BST(int start, int end)                                 // optimum BST for range
{
    if (end < start)    return 0;                           // out of range
    if (start >= end)   return 0;
    if (memo[start][end] != -1)    return memo[start][end];

    int curCost, minCost = INT_MAX;
    for (int i=start; i<=end; i++)                          // minimum value considering each element as root
    {
        curCost = BST(start, i - 1) + BST(i + 1, end) + weight[end] - weight[start-1] - frequency[i];   // cost if i is root
        if (curCost < minCost)
        {
            minCost = curCost;
            memo[start][end] = minCost;
        }
    }
    return memo[start][end];
}

int main()
{
    int n;
    while (cin>>n)
    {
        memset(memo, -1, sizeof(memo));
        weight[0] = 0;
        for (int i=1; i<=n; i++)
        {
            cin>>frequency[i];
            weight[i] = weight[i-1] + frequency[i];             // cumulative sum for W(i, j)
        }
        cout<<BST(1, n)<<endl;
    }
}