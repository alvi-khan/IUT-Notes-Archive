#include<bits/stdc++.h>
using namespace std;

int N;                                                  // N in NxN matrix
long long a[1000][1000], b[1000][1000], c[1000][1000];  // three matrices

long long frievalds()
{
    for (int i=0; i<10; i++)
    {
        long long randArr[N], res1[N], res2[N], match;
        for (int j=0; j < N; j++) randArr[j] = rand() % 2;   // generate random vector

        for (int j=0; j < N; j++)   // calculate B * r
        {
            res1[j] = 0;
            for (int k=0; k < N; k++)   res1[j] +=  b[j][k] * randArr[k];
        }

        for (int j=0; j < N; j++)   // Calculate A * Br
        {
            res2[j] = 0;
            for (int k=0; k < N; k++)   res2[j] += a[j][k] * res1[k];
        }

        for (int j=0; j < N; j++)   // Calculate C * r
        {
            match = 0;
            for (int k=0; k < N; k++)   match += c[j][k] * randArr[k];
            if (match != res2[j])       return 1;
        }
    }
    return 0;
}

int main()
{
    srand(unsigned(time(NULL)));
}