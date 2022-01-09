#include<stdio.h>

int main()
{
    int n = 11;
    int arr[11] = {1, 1, 1, 35, 47, 47, 55, 100, 150, 150, 150};
    int i, find, high = n-1, lo = 0, mid, flag = 0;

    for (i=0; i<n; i++) printf("%d ", arr[i]);


    printf("\nEnter Number to Search: ");
    scanf("%d", &find);

    while (lo <= high)
    {
        mid = (high + lo)/2;
        if (arr[mid] < find)    lo = mid + 1;
        else if (arr[mid] == find)
        {
            printf("%d is in index %d.", find, mid);
            high = mid;
            lo = mid;
            while (arr[lo-1] == arr[lo])    lo--;
            while (arr[high+1] == arr[high])    high++;
            if (lo < 0) lo = 0;
            if (high > n-1) high = n;
            printf("Loer Bound: %d. Upper Bound: %d.", lo, high);
            flag = 1;
            break;
        }
        else                    high = mid - 1;
    }

    if (flag == 0)  printf("Not Found. Loer Bound = %d. Upper Bound = %d", arr[high], arr[lo]);
}
