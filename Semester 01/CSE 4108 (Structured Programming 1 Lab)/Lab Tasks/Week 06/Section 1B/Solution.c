#include<stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];

    arr[0] = 1;
    arr[1] = 3;
    for (i=2; i<n; i++)                         //finds next numbers and stores in array
    {
        arr[i] = arr[i-1] + arr[i-2] + (i+1);
    }

    for (i=0; i<n; i++)                         //prints array
    {
        printf("%d", arr[i]);
        if (i!=n-1) printf(", ");
    }
}
