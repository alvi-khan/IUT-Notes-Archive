#include<bits/stdc++.h>
using namespace std;

int path[105][105] = {1000};    // shortest between node a and b
int cases = 0;

void fwa()                      // floyd warshall algorithm
{
    for (int k=1; k<=100; k++)
        for (int u=1; u<=100; u++)
            for (int v=1; v<=100; v++)
                path[u][v] = min(path[u][v], path[u][k] + path[k][v]);  // distance between u and v via k
}

void findAvg()                          // average of all valid paths
{
    int total = 0, count = 0;
    for (int i=1; i<=100; i++)
        for (int j=1; j<=100; j++)
        {
            if (i != j && path[i][j] != 1000)
            {
                total += path[i][j];
                count++;
            }
        }
    printf("Case %d: average length between pages = %.3f clicks\n", cases, (float) total/count);
}

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b))
    {
        cases++;

        for (int i=1; i<=100; i++)
            for (int j=1; j<=100; j++)
                path[i][j] = 1000;


        if (a == 0 && b == 0)   break;

        path[a][b] = 1;

        while(scanf("%d %d", &a, &b))
        {
            if (a == 0 && b == 0)   break;
            path[a][b] = 1;
        }

        fwa();
        findAvg();

    }
}