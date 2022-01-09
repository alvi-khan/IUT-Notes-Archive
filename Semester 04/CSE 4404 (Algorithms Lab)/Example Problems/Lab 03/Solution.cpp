#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1003;
int price[N], weight[N];
int dp[N][35];

int f(int i, int R)
{
    if(i == n || R == 0)
        return 0;
    if(dp[i][R] != -1)
        return dp[i][R];
    int pick, skip;
    if(weight[i] <= R)
        pick = price[i] + f(i + 1, R - weight[i]);
    else
        pick = 0;
    skip = f(i + 1, R);
    return dp[i][R] = max(pick, skip);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &price[i], &weight[i]);
        int q, ans = 0;
        memset(dp, -1, sizeof dp);
        scanf("%d", &q);
        while(q--)
        {
            int x;
            scanf("%d", &x);
            ans += f(0, x);
        }
        printf("%d\n", ans);
    }

    return 0;
}