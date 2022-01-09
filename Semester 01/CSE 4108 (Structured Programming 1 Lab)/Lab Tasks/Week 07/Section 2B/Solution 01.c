#include<stdio.h>

int flag = 0;

int check (int n)
{
    int j, k, res=0;
    char win;

    char a[n][n+1];

    for (j=0; j<n; j++)
    {
        scanf("%s", &a[j]);
    }

    for (j=0; j<n && flag<1; j++)                 // check rows
    {
        for (k=0; k<n; k++)
        {
            if (a[j][k] == 'X') res++;
        }
        if (res == n)   flag = 1;
        res = 0;
    }

    for (j=0; j<n && flag<1; j++)                 // check columns
    {
        for (k=0; k<n; k++)
        {
            if (a[k][j] == 'X') res++;
        }
        if (res == n)   flag = 1;
        res = 0;
    }

    for (j=0; j<n && flag<1; j++)                 // check top left to bottom right
    {
        if (a[j][j] == 'X') res++;
    }

    if (res == n)   flag = 1;
    res = 0;

    k = 0;
    for (j=n-1; j>=0 && flag<1; j--)              // check top right to bottom left
    {
        if (a[k][j] == 'X') res++;
        k++;
    }

    if (res == n)   flag = 1;
    res = 0;

    return flag;
}

int main()
{
    int T, n=3, i;
    scanf("%d", &T);

    for (i=1; i<=T; i++)
    {
        check(n);
        if (flag == 1)
        {
            flag = 0;
            printf("Case %d: X wins\n", i);
        }
        else    printf("Case %d: O wins\n", i);
    }
}
