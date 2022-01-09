#include <iostream>
using namespace std;

int G[50001];   // neighbour of each node
int reach[50001];   // how many people each node can reach (including self)
bool vis[50001];    // if a node has been visited or not

int dfs(int src)    // dfs traversal (kind of)
{
    vis[src] = true;    // mark as visited
    if (!vis[G[src]])   // if its neighbour is not visited
    {
        dfs(G[src]);    // traverse neighbour
        if (reach[src] == -1)   reach[src] = reach[G[src]] + 1; // self reach = neighbour's reach + 1
    }
    else if (vis[G[src]] && reach[G[src]] != -1)   reach[src] = reach[G[src]] + 1;  // if we know neighbours reach already
    else if (vis[G[src]] && reach[G[src]] == -1)    // if we do not know neighbours reach, but neighbour is visited, we have a loop; everything in loop has same value
    {
        int total = 1;  // total number of martians in loop
        int node = G[src];  // neighbour -> start of loop
        while (node != src) // get total number of people in loop
        {
            total++;
            node = G[node];
        }
        node = G[src];  // set to start again
        while (node != src) // set reach of everyone in loop
        {
            reach[node] = total;
            node = G[node];
        }
        reach[node] = total;    // set end member's reach
    }
    return reach[src];  // return reach of node
}

int findMaxReach(int n) // find the maximum possible reach of any node
{
    int max = 0;    // maximum reach
    int mvp = -1;   // person who has the maximum reach
    for (int i=1; i<=n; i++)    // for every unvisited node
    {
        if (!vis[i])
        {
            int value = dfs(i); // get the node's reach
            if (value > max)    // change max value if needed
            {
                max = value;
                mvp = i;
            }
        }
    }
    return mvp; // return person with maximum reach
}

int main()
{
    int t;  // test cases
    cin>>t;
    for (int j=1; j<=t; j++)    // for each test case
    {
        int n;
        cin>>n; // martians
        for (int i=1; i<=n; i++)
        {
            reach[i] = -1;  // set default reach of all martians in this test case
            vis[i] = false; // set default visit of all martians in this test case
            int u, v;
            cin>>u>>v;  // input edges
            G[u] = v;   // set edges in "graph"
        }
        cout<<"Case "<<j<<": "<<findMaxReach(n)<<endl;
    }
}