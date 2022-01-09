#include<bits/stdc++.h>
using namespace std;
const int nodeCount = 10;

vector<int>G[nodeCount];    // stores the adjacent list; each index contains a vector list of neighbours
int parent[nodeCount];      // stores parents of each node
bool visited[nodeCount];    // stores whether or not a node has been visited

void dfs(int source)
{
    for (auto neighbour : G[source])    // for each neighbour of the node
    {
        if (!visited[neighbour])        // if the neighbour is unvisited
        {
            visited[neighbour] = true;
            parent[neighbour] = source;
            dfs(neighbour);
        }
    }
}

void visitAll()    // locate and visit all unvisited nodes
{
    for (auto source : visited)     // for each node in the visited array
    {
        if (!visited[source])       // if the node is unvisited
        {
            parent[source] = -1;    // mark its parent as -1 to indicate it is a source
            dfs(source);            // dfs traversal to visit all nodes that can be visited from this source
        }
    }
}

int main()
{

}
