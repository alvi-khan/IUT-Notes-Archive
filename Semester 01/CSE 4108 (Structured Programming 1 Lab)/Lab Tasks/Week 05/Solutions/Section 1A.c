#include<stdio.h>

int main()
{
    int n, i, len;
    char a[100];
    scanf("%d", &n);
    scanf("%s", &a);

    len = strlen(a);

    for (i=0; i<len; i++)
    {
        a[i] = a[i] + n - 1;
    }

    printf("%s(encoded)\n", a);

    for (i=0; i<len; i++)
    {
        a[i] = a[i] - n + 1;
    }

    printf("%s(decoded)", a);
}
