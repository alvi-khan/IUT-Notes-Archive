#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define intPair pair<long long, int>        // storing as {weight, node}
const int maxCities = 100005;

vector<intPair> G[maxCities];               // graph
long long shortestPath[maxCities] = {0};    // shortest paths to each city
long long trainPaths[maxCities];            // shortest paths for trains to each city
long long cities, roads, trains;

void dijkstra(int source)                   // dijkstra
{
    priority_queue<intPair, vector<intPair>, greater<> > pq; // priority queue (min queue) of intPairs
    pq.push({0, source});
    shortestPath[source] = 0;

    while (!pq.empty()) // while there are members left to traverse
    {
        long long thisCost = pq.top().first;    // total weight from s -> u
        int thisNode = pq.top().second;         // the actual node u
        pq.pop();

        if (thisCost != shortestPath[thisNode])    continue; // if total weights do not match, this is an older version of the node -> skip

        for (auto neighbour : G[thisNode])  // for each neighbour of this node
        {
            long long neighbourCost = shortestPath[thisNode] + neighbour.first;    // total weight from s -> v
            int neighbourNode = neighbour.second;                       // the actual node v
            // if the current shortest path is the same as the train path, set train path to very large value so it can later be removed
            if (shortestPath[neighbourNode] == trainPaths[neighbourNode] && shortestPath[neighbourNode] >= neighbourCost)
            {
                trainPaths[neighbourNode] = LONG_LONG_MAX;
                shortestPath[neighbourNode] = neighbourCost; // store as shortest path to v
                pq.push({neighbourCost, neighbourNode});    // edge relaxed, so push to queue
            }
            // else normal change
            else if (shortestPath[neighbourNode] != trainPaths[neighbourNode] && shortestPath[neighbourNode] > neighbourCost) // if first path to v found or if shorter path found
            {
                shortestPath[neighbourNode] = neighbourCost; // store as shortest path to v
                pq.push({neighbourCost, neighbourNode});    // edge relaxed, so push to queue
            }
        }
    }
}

int main()
{

    cin>>cities>>roads>>trains;

    for (int i=1; i<=cities; i++)
    {
        G[i].clear();
        shortestPath[i] = LONG_LONG_MAX;
        trainPaths[i] = -1;
    }

    for (long long i=1; i<=roads; i++)
    {
        long long u, v, w;
        cin>>u>>v>>w;

        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }

    long long closedRoutes = 0;
    for (long long i=1; i<=trains; i++)
    {
        long long city, length;
        cin>>city>>length;

        if (trainPaths[city] == -1)     trainPaths[city] = length;          // if city has no train yet, set train
        else if (trainPaths[city] != -1)                                    // if train already exists, keep shorter one and remove other one
        {
            if (trainPaths[city] > length)  trainPaths[city] = length;
            closedRoutes++;
        }
    }

    for (int j=1; j<=cities; j++)                       // add shortest path trains only to graph
    {
        if (trainPaths[j] != -1)
        {
            G[1].push_back({trainPaths[j], j});
            G[j].push_back({trainPaths[j], 1});
        }
    }

    dijkstra(1);                                // dijkstra

    for (int j=1; j<=cities; j++)                       // find all remaining trains that are not equal to shortest paths since they need to be removed
    {
        if (trainPaths[j] != -1 && trainPaths[j] != shortestPath[j])   closedRoutes++;
    }

    cout<<closedRoutes<<endl;
}
