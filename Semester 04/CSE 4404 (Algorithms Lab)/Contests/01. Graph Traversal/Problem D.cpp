#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> G[101]; // store graph as adjacency list
bool vis[101];      // visited array
stack<int> order[101];  // store topological order


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
    int n, m;
    while (cin>>n>>m)   // while there are still inputs
    {
        for (auto v : G)    v.clear();  // clear graph
        for (int i=1; i<=n; i++) vis[i] = false;    // clear visited array

        if (n == 0 && m == 0)   break;  // if 0 0 then input has ended

        for (int i=1; i<=m; i++)    // otherwise take edge inputs
        {
            int src, dst;
            cin>>src>>dst;
            G[src].push_back(dst);  // push directed edge to adjacency list
        }

        visitAll(n);    // visit all edges -> topological sort

        while (!order->empty()) // pop stack to get order
        {
            cout<<order->top()<<" ";
            order->pop();
        }
        cout<<endl; // every output on new line -> instruction
    }
}