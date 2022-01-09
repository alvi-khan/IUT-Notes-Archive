#include<bits/stdc++.h>
using namespace std;

int crossings = 0;
int sound[105][105] = {0};      // sound on street from a to b

void fwa()                      // floyd warshall algorithm
{
    for (int k=1; k<=crossings; k++)
        for (int u=1; u<=crossings; u++)
            for (int v=1; v<=crossings; v++)
            {
                int soundLevel = min(sound[u][v], max(sound[u][k], sound[k][v]));   // sound between u and v going via k
                sound[u][v] = sound[v][u] = soundLevel;                             // two way street
            }
}

int main()
{
    int sounds, queries, cases = 0;
    while (cin>>crossings>>sounds>>queries)
    {
        cases++;
        if (crossings == 0 && sounds == 0 && queries == 0)  break;

        for (int i=1; i<=crossings; i++)
            for (int j=1; j<=crossings; j++)    sound[i][j] = INT_MAX;          // set values to infinity initially

        while (sounds--)
        {
            int crossingA, crossingB, soundLevel;
            cin>>crossingA>>crossingB>>soundLevel;
            sound[crossingB][crossingA] = sound[crossingA][crossingB] = soundLevel;
        }

        fwa();

        if (cases != 1) cout<<endl;     // blank line before every output except first
        cout<<"Case #"<<cases<<endl;
        while(queries--)
        {
            int crossingA, crossingB;
            cin>>crossingA>>crossingB;
            int soundLevel = sound[crossingA][crossingB];
            if (soundLevel == INT_MAX)  cout<<"no path"<<endl;
            else                        cout<<soundLevel<<endl;
        }
    }
}