#include<stdio.h>

int main()
{
    int T, i, j, k, c, d, flag = 0;
    char a[5];
    scanf("%d", &T);

    for (i=1; i<=T; i++)
    {
        for (j=1; j<=4; j++)
        {
            scanf("%s", &a);

            if (flag == 1)  continue;

            for (k=0; k<=4; k++)
            {
                if (a[k] == 'R')        //store coordinates of R
                {
                    flag = 1;
                    c = j;
                    d = k+1;
                    break;
                }
            }
        }

        if (flag == 1)
        {
            flag = 0;
            printf("Case %d: Ralph is in %d, %d", i, c, d);
        }
        else    printf("Case %d: Ralph is Good!", i);
    }
}
