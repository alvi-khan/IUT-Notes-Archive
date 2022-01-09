#include <bits/stdc++.h>
using namespace std;
const int nodeCount = 10;

vector<int>G[nodeCount];    // stores the adjacency list; each index will contains a vector list of neighbours
int level[nodeCount];       // stores the level of each node
int parent[nodeCount];      // stores parent for each node
bool visited[nodeCount];    // stores whether or not a node has been visited

void bfs (int source)
{
    queue <int>q;           // queue for nodes that need to be traversed
    q.push(source);
    visited[source] = true;
    level[source] = 0;
    parent[source] = -1;
    while (!q.empty())
    {
        int thisNode = q.front();
        q.pop();            // remove node that is being traversed from queue
        for (auto neighbour : G[thisNode])      // for each of the neighbours of this node
        {
            if (!visited[neighbour])    // if the neighbour is unvisited
            {
                visited[neighbour] = true;
                level[neighbour] = level[thisNode] + 1;
                parent[neighbour] = thisNode;
                q.push(neighbour);
            }
        }
    }
}

int main()
{
    
}
