#include<bits/stdc++.h>
using namespace std;

int frequency[100] = {0};       // frequencies of the elements
int weight[100] = {0};          // weights of the elements; weight[i] = sum(weight[0] -> weight[i-1])
int memo[100][100];

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
    
}