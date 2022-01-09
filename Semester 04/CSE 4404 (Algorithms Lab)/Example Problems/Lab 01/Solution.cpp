#include <bits/stdc++.h>
using namespace std;

char G[105][105];
bool vis[105][105];

int ans;

/*
2 1
LLLLLLLLL
LLWWLLWLL
LWWLLLLLL
LWWWLWWLL
LLLWWWLLL
LLLLLLLLL
LLLWWLLWL
LLWLWLLLL
LLLLLLLLL
*/

void dfs(int sx, int sy)
{
    if(sx < 0 || sy < 0)
        return;
    if(G[sx][sy] == 0 || vis[sx][sy] == true || G[sx][sy] == 'L')
        return;
    vis[sx][sy] = true;
    ans++;
    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            if(i || j)
                dfs(sx + i, sy + j);
        }
    }
}

int main()
{
    int cases;
    scanf("%d ", &cases);
    char s[105];
    // cases = 0
    while(cases--)
    {
        int rows = 0;
        // rows = 1
        while(gets(s))
        {
            if(s[0] == '\0')
                break;
            if(s[0] != 'W' && s[0] != 'L')
            {
                int x, y;
                // x = 3, y = 2
                sscanf(s, "%d %d", &x, &y);
                ans = 0;
                dfs(x - 1, y - 1);
                printf("%d\n", ans);
                memset(vis, false, sizeof(vis));
            }
            else
            {
                sscanf(s, "%s", G[rows]);
                rows++;
            }
        }
        memset(G, 0, sizeof(G));
        if(cases)
            puts("");

    }

    return 0;
}