#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 1003;

LL A[N][N], B[N][N], C[N][N];
LL r[N], Br[N], ABr[N], Cr[N];

int main()
{
    srand(time(NULL));
    int n;
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%lld", &A[i][j]);
                B[i][j] = A[i][j];
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%lld", &C[i][j]);
            }
        }
        bool flag = true;
        for(int t = 0; t < 20 && flag; t++)
        {
            for(int i = 0; i < n; i++)
                r[i] = abs(rand() & 7);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    Br[i] += B[i][j] * r[j];
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    ABr[i] += A[i][j] * Br[j];
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    Cr[i] += C[i][j] * r[j];
            
            for(int i = 0; i < n && flag; i++)
                if(ABr[i] != Cr[i])
                    flag = false;
            
            memset(Br, 0, sizeof Br);
            memset(ABr, 0, sizeof ABr);
            memset(Cr, 0, sizeof Cr);
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}