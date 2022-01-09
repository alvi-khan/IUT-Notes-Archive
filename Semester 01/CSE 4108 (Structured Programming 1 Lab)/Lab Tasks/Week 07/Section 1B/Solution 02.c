#include<stdio.h>

int main()
{
    int T, i, j, k, m, n, x, y, flag = 0, b=0;
    int c[100], d[100];
    scanf("%d", &T);

    for (i=1; i<=T; i++)
    {
        scanf("%d %d", &m, &n);
        char a[m][n+1];
        for (j=0; j<m; j++)
        {
            scanf("%s", &a[j]);

            for (k=0; k<n; k++)
            {
                if (a[j][k] == 'R')     // store the coordinates or R
                {
                    c[b] = j+1;
                    d[b] = k+1;
                    b++;
                    flag = 1;           // flag = 1 to indicate R is present
                }
            }
        }

        if (flag == 1)
        {
            for (j=0; j<b; j++)     // check everything surrounding R
            {
                x = c[j]-1;
                y = d[j]-1;
                if (a[x][y-1] == '#' && a[x][y+1] == '#' && a[x-1][y] == '#' && a[x-1][y-1] == '#' && a[x-1][y+1] == '#' && a[x+1][y] == '#' && a[x+1][y+1] == '#' && a[x+1][y-1] == '#')   flag = 2;
            }
        }

        if (flag == 2)  printf("Case %d: Ralph is Good!", i);
        else if (flag == 1)
        {
            printf("Case %d: Ralph is in ", i);
            for (j=0; j<b; j++)
            {
                printf("%d, %d", c[j], d[j]);
                if (j != b-1)   printf(" and ");
            }
        }
        else    printf("Case %d: Ralph has escaped!", i);

        b = 0;
        flag = 0;
    }
}
