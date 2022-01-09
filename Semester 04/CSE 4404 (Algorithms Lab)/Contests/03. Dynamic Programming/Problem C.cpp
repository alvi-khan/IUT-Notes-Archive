#include<bits/stdc++.h>
using namespace std;

int coins[110];
int memo[110][50100];   // memoize (coin, target)

int f(int i, int target)
{
    if (memo[i][target] != -1)  return memo[i][target]; // memoized value
    if (i == 0 || target == 0)  return 0;               // no more coins left / target reached
    if (coins[i] > target)      return f(i-1, target);  // coin cannot be taken, move on
    return memo[i][target] = max(f(i-1, target), f(i-1, target-coins[i]) + coins[i]);   // check maximum of taking coin or not taking it
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        memset(memo, -1, sizeof(memo));
        int m, total = 0;
        cin>>m;
        for (int i=1; i<=m; i++)
        {
            cin>>coins[i];
            total += coins[i];              // keep track of total -> need to reach half this amount
        }
        int setOne = f(m, total/2); // knapsack
        cout<<(total - setOne) - setOne<<endl;
    }
}