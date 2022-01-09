#include <bits/stdc++.h>
using namespace std;
#define intPair pair<int, int>
const int maxCities = 500;

vector<intPair> G[maxCities];   // graph
int cost[maxCities];            // minimum cost of travelling from source to each city

void dijkstra(int source)
{
    priority_queue<intPair, vector<intPair>, greater<intPair> > pq;
    pq.push({source, 0});
    cost[source] = 0;

    while (!pq.empty())
    {
        int thisNode = pq.top().first;
        int thisCost = pq.top().second;
        pq.pop();

        if (thisCost != cost[thisNode])  continue;  // older node -> ignore

        for (auto neighbour:G[thisNode])    // for each neighbour
        {
            int neighbourNode = neighbour.first;
            int neighbourCost = max(cost[thisNode], neighbour.second);  // maximum value on path to this this node from source
            if ((cost[neighbourNode] == -1) || (cost[neighbourNode] > neighbourCost))   // if this value is less than current cost, take it
            {
                cost[neighbourNode] = neighbourCost;
                pq.push({neighbourNode, neighbourCost});
            }
        }
    }
}

int main()
{
    int T;
    cin>>T;
    for (int i=1; i<=T; i++)
    {
        int cities, roads;
        cin>>cities>>roads;

        for (int j=0; j<cities; j++)    // clear graph and cost values for new source
        {
            G[j].clear();
            cost[j] = -1;
        }

        for (int j=1; j<=roads; j++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            G[u].push_back({v, w}); // bi-directional
            G[v].push_back({u, w});
        }

        int t;
        cin>>t;

        dijkstra(t);

        cout<<"Case "<<i<<":"<<endl;    // output
        for (int j=0; j<cities; j++)
        {
            if (cost[j] == -1)  cout << "Impossible" << endl;
            else                cout << cost[j] << endl;
        }
    }
}