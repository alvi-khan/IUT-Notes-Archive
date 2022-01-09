#include <iostream>
#include <vector>
using namespace std;
#define intPair pair<int, int>  // pair -> (node, weight)
const int up = 1001;        // maximum number of systems & time

vector<intPair> G[up];      // Graph -> each node holds vector list of weight edges to other nodes
int dist[up];               // distances from source

int bellmanFord (int nodes) // bellman-ford algorithm
{
    for (int i=0; i<nodes-1; i++)   // loop V-1 times
    {
        for (int u=0; u<nodes; u++) // for each of the nodes
        {
            for (auto v: G[u])      // for each of the neighbours of the node
            {
                int cost = dist[u] + v.second;  // find distance from s -> v
                if (cost < dist[v.first])   dist[v.first] = cost;   // if min, replace
            }
        }
    }

    int cycle = 0;  // flag for cycle detection

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
    return cycle;   // returns 0 if no cycle, 1 if cycle
}

int main()
{
    int testCases;  // the number of test cases
    cin>>testCases;

    for (int i=0; i<testCases; i++) // for each test case
    {
        int nodes, edges;
        cin>>nodes>>edges;
        for (int j=0; j<nodes; j++) // clear gra and reset distances
        {
            G[j].clear();
            dist[j] = up;
        }
        for (int j=0; j<edges; j++) // input for edges
        {
            int u, v, t;
            cin>>u>>v>>t;
            G[u].push_back({v, t});
        }
        dist[0] = 0;    // source node distance is always 0
        if (bellmanFord(nodes))    cout<<"possible"<<endl;  // bellman-ford returns 1 if cycle found
        else                        cout<<"not possible"<<endl;
    }
}