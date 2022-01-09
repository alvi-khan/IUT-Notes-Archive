#include <bits/stdc++.h>
using namespace std;
#define intPair pair<int, int>  // store weighted graph as pair {node, weight}
const int nodeCount = 10;       // maximum nodes in graph

vector<intPair> G[nodeCount];   // Graph where each node has vector list of neighbours with edge weights
int parent[nodeCount];          // store parents of each node
int level[nodeCount];           // store level of each node
int dist[nodeCount];            // store shortest distance from source

int dijkstra (int source)   // dijkstra traversal
{
    priority_queue<intPair, vector<intPair>, greater<intPair> > pq; // priority queue (min queue) of intPairs
    pq.push({source, 0});
    dist[source] = 0;

    while (!pq.empty())                 // while there are members left to traverse
    {
        int thisNode = pq.top().first;  // the actual node u
        int thisCost = pq.top().second; // total weight from s -> u
        pq.pop();

        if (thisCost != dist[thisNode])    continue; // if total weights do not match, this is an older version of the node -> skip

        for (auto neighbour : G[thisNode])          // for each neighbour of this node
        {
            int neighbourNode = neighbour.first;    // the actual node v
            int neighbourCost = dist[thisNode] + neighbour.second;                  // total weight from s -> v
            if (dist[neighbourNode] == -1 || dist[neighbourNode] > neighbourCost)   // if first path to v found or if shorter path found
            {
                dist[neighbourNode] = neighbourCost;        // store as shortest path to v
                level[neighbourNode] = level[thisNode] + 1; // increment level
                parent[neighbourNode] = thisNode;           // set new parent
                pq.push({neighbourNode, neighbourCost});    // edge relaxed, so push to queue
            }
        }
    }
}

int main()
{
    
}