#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
double points[N][2];
int pr[N];
int sz[N];

struct edge
{
    int u, v;
    double w;
    bool operator<(const edge &p) const
    {
        return w < p.w;
    }
};

vector<edge>e;

void makeSet(int n)
{
    for(int i = 0; i < n; i++)
    {
        pr[i] = i;
        sz[i] = 1;
    }
}

int findSet(int v)
{
    if(v == pr[v])
        return v;
    return pr[v] = findSet(pr[v]);
}

void kruskal(int n, int r)
{
    double roadLen, railLen;
    roadLen = railLen = 0;
    int roadCount = 0;
    makeSet(n);
    sort(e.begin(), e.end());
    for(int i = 0; i < e.size(); i++)
    {
        int u = findSet(e[i].u);
        int v = findSet(e[i].v);
        if(u != v)
        {
            if(e[i].w <= r)
            {
                roadCount++;
                roadLen += e[i].w;
            }
            else
                railLen += e[i].w;
            if(sz[u] < sz[v])
                swap(u, v);
            pr[v] = u;
        }
    }
    cout << (n - roadCount) << " ";
    cout << fixed << setprecision(0) << roadLen << " " << railLen << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cc = 0;
    int t;
    cin >> t;
    while(t--)
    {
        int n, r;
        cin >> n >> r;
        for(int i = 0; i < n; i++)
            cin >> points[i][0] >> points[i][1];
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                edge tp;
                tp.u = i;
                tp.v = j;
                tp.w = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
                e.push_back(tp);
            }
        }
        cout << "Case #" << (cc + 1) << ": ";
        cc++;
        kruskal(n, r);
        e.clear();
    }
    return 0;
}