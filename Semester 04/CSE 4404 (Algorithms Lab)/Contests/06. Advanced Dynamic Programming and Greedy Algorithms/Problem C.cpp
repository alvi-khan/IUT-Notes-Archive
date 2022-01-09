#include <bits/stdc++.h>
using namespace std;

map<int, int> parent;                           // easy storage of sets

int findRoot (int node)                         // find representative of node
{
    if (parent[node] == node)    return node;   // current element is a parent
    else
    {
        if (parent[parent[node]] != parent[node])   parent[node] = findRoot(parent[node]);
        // if current parent of element is not a representative,
        // find the representative and set the parent (memoizing)
        return parent[node];                    // return representative
    }
}

int main()
{
    long long crackers, N, M;
    cin>>N>>M;
    crackers = N;                       // initially everyone gets a cracker

    while (M--)
    {
        int a, b;
        cin>>a>>b;

        if (!parent[a]) parent[a] = a;  // every node is its own representative at first
        if (!parent[b]) parent[b] = b;

        int rootA = findRoot(a), rootB = findRoot(b);
        if (rootA != rootB)             // if nodes have different representatives, they are from different sets
        {
            parent[rootB] = rootA;      // joining sets
            crackers--;                 // one more member in set so one less cracker
        }
    }
    cout<<crackers;
}