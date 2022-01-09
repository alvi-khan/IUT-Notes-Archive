#include<stdio.h>

int arr[1000], target;

int binarySearch(int start, int end)
{
    if (start>end)  return -1;

    int mid = (start+end)/2;

    if (arr[mid] == target)     return mid;
    else if (arr[mid]>target)   return binarySearch(start, mid-1);
    else    return binarySearch(mid+1, end);
}

int main()
{
    int i=0;

    while(scanf("%d", &arr[i]))
    {
        if (arr[i] >= 0) i++;
        else            break;
    }

    scanf("%d", &target);

    printf("%d", binarySearch(0, i-1));
}
