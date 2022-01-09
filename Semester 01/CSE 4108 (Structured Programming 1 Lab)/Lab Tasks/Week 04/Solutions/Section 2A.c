#include<stdio.h>

int main()
{
    printf("%d\n", (2+3)/2);

    int n, i, a, res=0;
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        scanf("%d", &a);
        res = res+a;
    }

    printf("%d", res/n);
}
