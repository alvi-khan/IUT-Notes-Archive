#include <bits/stdc++.h>
using namespace std;

const int N = 10004;
int n;
int p[N];

int binarySearch(int lb, int ub, int x)
{
    int mid;
    while(lb <= ub)
    {
        mid = (lb + ub) / 2;
        if(p[mid] == x)
            return mid;
        else if(p[mid] > x)
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return -1;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        int m;
        scanf("%d", &m);
        sort(p, p + n);

        int mn = INT_MAX;
        int price1, price2;
        for(int i = 0; i < n; i++)
        {
            int curr = p[i];
            int rem = m - p[i];
            if(abs(curr - rem) < mn)
            {
                int idx = binarySearch(i + 1, n, rem);
                if(idx != -1)
                {
                    price1 = curr;
                    price2 = rem;
                    mn = abs(curr - rem);
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", price1, price2);
    }
    return 0;
}