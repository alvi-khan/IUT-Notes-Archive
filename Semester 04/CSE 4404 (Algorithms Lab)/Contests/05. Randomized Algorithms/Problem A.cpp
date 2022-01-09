// Test Code Here: https://codeforces.com/gym/101341/submit

#include<bits/stdc++.h>
using namespace std;

int N;
const int mod = 1e9 + 7;
long long a[1005][1005], b[1005][1005], c[1005][1005];

long long frievald()
{
    for (int i=0; i<10; i++)
    {
        long long randArr[N], res1[N], res2[N], match;
        for (int j=0; j < N; j++) randArr[j] = rand() % 2;   // generate random vector

        for (int j=0; j < N; j++)   // calculate B * r
        {
            res1[j] = 0;
            for (int k=0; k < N; k++)   res1[j] = (res1[j] + (b[j][k] * randArr[k])) % mod;
        }

        for (int j=0; j < N; j++)   // Calculate A * Br
        {
            res2[j] = 0;
            for (int k=0; k < N; k++)   res2[j] = (res2[j] + (a[j][k] * res1[k])) % mod;
        }

        for (int j=0; j < N; j++)   // Calculate C * r
        {
            match = 0;
            for (int k=0; k < N; k++)   match = (match + (c[j][k] * randArr[k])) % mod;
            if (match != res2[j])       return 1;
        }
    }
    return 0;
}

int main()
{
    srand(unsigned(time(NULL)));
    scanf("%d", &N);

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) scanf("%lld", &a[i][j]);

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) scanf("%lld", &b[i][j]);

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++) scanf("%lld", &c[i][j]);

    if (frievald() == 1)    printf("NO");
    else                    printf("YES");
}