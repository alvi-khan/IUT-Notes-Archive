#include <bits/stdc++.h>
using namespace std;
#define intPair pair<int, int>
const int maxCities = 101;

vector<intPair>graph[maxCities];    // graph to store adjacency list
int shortestPath[maxCities];        // stores shortest paths to every node through bellman-ford
int levelWeights[maxCities];        // shortest paths to target at every level

void traverse(int cityCount)
{
    for (int i=0; i<cityCount-1; i++)               // loop V-1 times
    {
        for (int node = cityCount-1; node>0; node--)    // loop over nodes backwards
        {
            for (auto neighbour : graph[node])          // set shortest paths for all neighbours
            {
                if (shortestPath[node] != INT_MAX && shortestPath[neighbour.first] > (shortestPath[node] + neighbour.second))
                    shortestPath[neighbour.first] = shortestPath[node] + neighbour.second;
            }
        }
        levelWeights[i] = shortestPath[cityCount];  // set shortest path too target for this level
    }
}

int main()
{
    int testCases;
    cin>>testCases;

    for (int i=1; i<=testCases; i++)
    {
        unordered_map<string, int> umap;                    // city names converted to indices using hashing
        memset(graph, 0, sizeof(graph));              // clearing graph and levelWeights for every scenario
        memset(levelWeights, 0, sizeof(levelWeights));

        int cities;
        cin>>cities;

        for (int ii=1; ii<=cities; ii++)
        {
            string cityName;
            cin>>cityName;
            umap[cityName] = ii;                    // set index in hash table
            shortestPath[ii] = INT_MAX;             // having to clear shortest paths separately -> cannot set to high value with memset
        }

        shortestPath[1] = 0;                        // source node

        int flights;
        cin>>flights;

        for (int ii=1; ii<=flights; ii++)
        {
            string cityA, cityB;
            int cost;
            cin>>cityA>>cityB>>cost;
            graph[umap.find(cityA)->second].push_back({umap.find(cityB)->second, cost});    // use indices from hashtable to store in graph
        }

        traverse(cities);   // bellman-ford -> shortest paths at every level set

        int queries;
        cin>>queries;

        cout<<"Scenario #"<<i<<endl;
        for (int ii=1; ii<=queries; ii++)
        {
            int level;
            cin>>level;
            if (level > cities-2)   level = cities - 2;         // in case queries are larger than max level
            if (levelWeights[level] == INT_MAX) cout<<"No satisfactory flights"<<endl;  // if no flights (no path), shortest path for that level would be set to INT_MAX
            else                                 cout<<"Total cost of flight(s) is $"<<levelWeights[level]<<endl;
        }
        if (i != testCases) cout<<endl;                         // skip the extra line at the end -> presentation error otherwise
    }
}
