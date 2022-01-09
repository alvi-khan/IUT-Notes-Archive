#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int>graph[], bool *visited, int *distance, int source)  // bfs traversal
{
    queue<int> q;                           // queue to store nodes that need to be traversed
    q.push(source);                         // first traverse source
    visited[source] = true;
    distance[source] = 0;
    while(!q.empty())                       // while there are still nodes that need to be traversed, keep going
    {
        int node = q.front();
        q.pop();
        for (auto neighbour : graph[node])  // for each neighbour of the node
        {
            if (!visited[neighbour])        // if the neighbour was not previously visited
            {
                visited[neighbour] = true;
                distance[neighbour] = distance[node] + 6;   // its distance is the distance of its parent + 6 (every edge has weight 6)
                q.push(neighbour);          // push the neighbour onto the queue to be traversed
            }
        }
    }

}

int main()
{
    int queries;                                // stores total number of queries
    cin>>queries;
    while(queries--)                            // while there are more queries, keep looping
    {
        int nodes, edges;                       // no. of nodes and edges in current graph
        cin>>nodes>>edges;
        vector<int> graph[nodes+1];             // stores the graph as adjacency list; indexing starts from 1
        for (int i=0; i<edges; i++)             // collect all edges in graph
        {
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);              // must store for both nodes since undirected
            graph[v].push_back(u);
        }

        int source;
        bool visited[nodes+1];                  // marks for nodes that have been visited
        int distance[nodes+1];                  // distance of each node from source

        for (int i=0; i<nodes+1; i++)           // setting default values for visited and distance
        {
            visited[i] = false;
            distance[i] = -1;
        }

        cin>>source;
        bfs(graph, visited, distance, source);  // traversing graph

        for (int i=1; i<nodes+1; i++)           // printing distances after traversal
        {
            if (i == source) continue;          // do not print source itself (0 distance) -> instruction
            else    cout<<distance[i]<<" ";
        }
        cout<<endl;                             // blank line at end -> instruction
    }
}