#include <iostream>
#include <string>
#include <queue>
using namespace std;



int tour (string src, const string& dest)   // essentially BFS traversal
{
    if (src == dest)    return 0;   // if start and end locations same
    int level[8][8] = {0};          // keeps track of the distance of each location from start
    bool vis[8][8] = {false};       // keep track of if a location has already been visited

    queue <string>q;                // queue for locations that need to be traversed
    q.push(src);                    // will start traversing at source
    vis[src[0] - 97][src[1]-49] = true ;    // converting characters to integers;
    level[src[0] - 97][src[1]-49] = 0;      // source is at 0

    while (!q.empty())                      // while there are still nodes to traverse
    {
        string u = q.front();
        q.pop();

        for (int i=-2; i<=2; i++)           // for each valid neighbour
        {
            for (int j=-2; j<=2; j++)
            {
                if ((i == -2 && ( j == -1 || j == 1)) || (i == -1 && (j == -2 || j == 2)) || (i == 2 && ( j == -1 || j == 1)) || (i == 1 && (j == -2 || j == 2)))   // valid knight moves
                {
                    string v = u;
                    v[0] += i;
                    v[1] += j;

                    if (v == dest)  return level[u[0] - 97][u[1]-49] + 1;   // if this neighbour is the dest, return level

                    else if (!(v[0] < 'a' || v[0] > 'h' || v[1] < '1' || v[1] > '8' || vis[v[0] - 97][v[1]-49]))    // if withing bounds and unvisited
                    {
                        vis[v[0] - 97][v[1]-49] = true ;    // mark as visited
                        level[v[0] - 97][v[1]-49] = level[u[0] - 97][u[1]-49] + 1;  // mark its level
                        q.push(v);  // push to queue
                    }
                    v[0] -= i;
                    v[1] -= j;
                }
            }
        }
    }
}

int main()
{
    string source, dest;
    while(cin>>source>>dest)
    {
        cout<<"To get from "<<source<<" to "<<dest<<" takes "<<tour(source, dest)<<" knight moves."<<endl;
    }
}