#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define intPair pair<int, int>      // make life easy
const int maxServers = 20001;

vector<intPair> G[maxServers];      // Graph stores servers and vector of pair (latency, server)
int latency[maxServers];            // latency of server from source

int dijkstra (int source, int target)   // dijkstra traversal
{
    priority_queue<intPair, vector<intPair>, greater<intPair> > pq; // priority queue (min queue) of intPairs
    pq.push({0, source});
    latency[source] = 0;

    while (!pq.empty()) // while there are members left to traverse
    {
        int thisCost = pq.top().first;  // total weight from s -> u
        int thisNode = pq.top().second; // the actual node u
        pq.pop();

        if (thisCost != latency[thisNode])    continue; // if total weights do not match, this is an older version of the node -> skip

        for (auto neighbour : G[thisNode])  // for each neighbour of this node
        {
            int neighbourCost = latency[thisNode] + neighbour.first;    // total weight from s -> v
            int neighbourNode = neighbour.second;                       // the actual node v
            if (latency[neighbourNode] == -1 || latency[neighbourNode] > neighbourCost) // if first path to v found or if shorter path found
            {
                latency[neighbourNode] = neighbourCost; // store as shortest path to v
                pq.push({neighbourCost, neighbourNode});    // edge relaxed, so push to queue
            }
        }
    }
    return latency[target]; // return the minimum latency for source -> target; returns -1 if never reached
}

int main()
{
    int tests;      // number of test cases
    cin>>tests;

    for (int caseNo = 1; caseNo <= tests; caseNo++) // for each test case
    {
        int servers, cables, start, end;
        cin>>servers>>cables>>start>>end;   // input

        for (int i=0; i<servers; i++)   // clear graph & latencies
        {
            G[i].clear();
            latency[i] = -1;
        }

        for (int conn=0; conn<cables; conn++)   // edge inputs
        {
            int u, v, weight;
            cin>>u>>v>>weight;

            G[u].push_back({weight, v});    // pushing edges to graph (bi-directional)
            G[v].push_back({weight, u});
        }

        int time = dijkstra(start, end);    // run dijkstra
        if (time != -1) cout<<"Case #"<<caseNo<<": "<<time<<endl;
        else            cout<<"Case #"<<caseNo<<": unreachable"<<endl;  // dijkstra returns -1 if target
    }
}