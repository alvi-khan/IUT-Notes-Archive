#include <bits/stdc++.h>
using namespace std;
#define intPair pair<int, int>      // pair -> (node, weight)
const int nodeCount = 1001;         // maximum number of systems & time

vector<intPair> G[nodeCount];       // Graph -> each node holds vector list of weighted edges to other nodes
int dist[nodeCount];                // distances from source

void bellmanFord (int nodes)         // bellman-ford algorithm
{
    for (int i=0; i<nodes-1; i++)   // loop V-1 times
    {
        for (int u=0; u<nodes; u++) // for each of the nodes
        {
            for (auto v: G[u])      // for each of the neighbours of the node
            {
                int cost = dist[u] + v.second;                      // find distance from s -> v
                if (cost < dist[v.first])   dist[v.first] = cost;   // if minimum, replace
            }
        }
    }

    int cycle = 0;              // flag for cycle detection

    for (int u=0; u<nodes; u++) // loop over all edges once more
    {
        for (auto v: G[u])
        {
            int cost = dist[u] + v.second;
            if (cost < dist[v.first])   // if there is another decrease, there has to be a cycle
            {
                cycle = 1;
                break;
            }
        }
    }
}

int main()
{
    
}