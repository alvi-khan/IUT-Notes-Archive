#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 101;
vector<pii>G[N];
int dist[N];
int ct;

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty())
    {
        int uw = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(uw != dist[u] || uw >= ct)
            continue;
        int sz = G[u].size();
        for(int i = 0; i < sz; i++)
        {
            int vw = G[u][i].first;
            int v = G[u][i].second;
            int cost = dist[u] + vw;
            if(dist[v] > cost)
            {
                dist[v] = cost;
                pq.push({cost, v});
            }
        }
        
    }
}


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, e;
        scanf("%d", &n);
        scanf("%d", &e);
        scanf("%d", &ct);
        int m;
        scanf("%d", &m);
        int u, v, w;
        for(int i = 1; i <= n; i++)
        {  
            G[i].clear();
            dist[i] = INT_MAX / 2;
        }
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            G[v].push_back({w, u});
        }
        
        dijkstra(e);
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(dist[i] <= ct)
                ans++;
        printf("%d\n", ans);
        if(t)
            puts("");
        
    }

    return 0;
}