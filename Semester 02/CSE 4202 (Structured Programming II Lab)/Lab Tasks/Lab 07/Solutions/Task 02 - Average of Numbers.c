#include<stdio.h>

int n, d, arr1[100][100], arr2[100][100];

void average(int i, int j)
{
    int a, b, k, sum = 0, count = 0;
    if ((i-d) > -1) a = i - d;
    else            a = 0;

    if ((j-d) > -1) b = j - d;
    else            b = 0;

    for (a = a; a<=i+d; a++)
    {
        if (a>n-1)  break;
        for (k = b; k<=j+d; k++)
        {
            if (a == i && k == j)   continue;
            if (k>n-1)  break;
            sum += arr1[a][k];
            count++;
        }
    }

    arr2[i][j] = sum/count;
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &d);

    for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d", &arr1[i][j]);

    for (i=0; i<n; i++) for (j=0; j<n; j++) average(i, j);

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++) printf("%d ", arr2[i][j]);
        printf("\n");
    }
}
