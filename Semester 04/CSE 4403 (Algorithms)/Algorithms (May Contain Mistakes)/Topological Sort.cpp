#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> G[101]; // store graph as adjacency list
bool vis[101];      // visited array
stack<int> order[101];  // store reversed topological order


void dfs(int src)   // dfs traversal
{
    for (auto v : G[src])   // for each neighbour of node
    {
        if (!vis[v])    // if unvisited
        {
            vis[v] = true;  // mark as visited
            dfs(v);         // traverse
            order->push(v); // push to stack once traversal complete
        }
    }
}

void visitAll(int size) // visit every node
{
    for (int i=1; i<=size; i++)
    {
        if (!vis[i])    // for each unvisited node
        {
            vis[i] = true;  // mark as visited
            if (!G[i].empty())  dfs(i); // if it has neighbours, traverse
            order->push(i); // push to stack
        }
    }
}

int main()
{
    
}