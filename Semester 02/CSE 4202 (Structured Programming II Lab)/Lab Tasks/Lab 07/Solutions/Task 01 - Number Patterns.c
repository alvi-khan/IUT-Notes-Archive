#include<stdio.h>

int arr[100], i = 0, n;

divide(int n)
{
    while(n>26)
    {
        arr[i] = n%26;
        if (arr[i] == 0)    arr[i] = 26;
        n = n/26;
        i++;
    }
    arr[i] = n;
}

int main()
{
    while(scanf("%d", &n) == 1)
    {
        divide(n);
        for (i = i; i>-1; i--)  printf("%c", 64+arr[i]);
        i=0;
        printf("\n");
    }
}
