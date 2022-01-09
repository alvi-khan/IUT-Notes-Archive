#include<bits/stdc++.h>
using namespace std;

int V;                          // vertices
int weight[100][100] = {0};     // edge weights

void fwa()                      // floyd warshall algorithm
{
    for (int k=1; k<=V; k++)
        for (int u=1; u<=V; u++)
            for (int v=1; v<=V; v++)
                weight[u][v] = weight[v][u] = min(weight[u][v], weight[u][k] + weight[k][v]);   // weight of path u -> v via k
}

int main()
{
    
}