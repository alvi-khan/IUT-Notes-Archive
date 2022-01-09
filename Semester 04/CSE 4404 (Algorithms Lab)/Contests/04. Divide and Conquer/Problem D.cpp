#include<bits/stdc++.h>
using namespace std;

int arr[2000005];

void merge(int lb, int mid, int ub)
{
    int temp[ub - lb + 1];
    int i = lb, j = mid + 1, k = 0;

    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)        // any remaining values
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= ub)         // any remaining values
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    i = lb;
    j = 0;
    while (i <= ub)         // fix main array
    {
        arr[i] = temp[j];
        i++;
        j++;
    }
}

void mergeSort(int lb, int ub)
{
    if (lb == ub)   return;         // single element reached
    int mid = (lb + ub - 1) / 2;    // mid-point
    mergeSort(lb, mid);             // dividing
    mergeSort(mid + 1, ub);
    merge(lb, mid, ub);             // merging
}

int main()
{
    int N = -1;
    while (true)
    {
        scanf("%d", &N);
        if (N == 0) break;

        for (int i=0; i<N; i++) scanf("%d", &arr[i]);

        mergeSort(0, N-1);

        for (int i=0; i<N; i++)
        {
            printf("%d", arr[i]);
            if (i != (N - 1))   printf(" ");    // space after every element except last
        }
        printf("\n");                           // newline after every line
    }
}