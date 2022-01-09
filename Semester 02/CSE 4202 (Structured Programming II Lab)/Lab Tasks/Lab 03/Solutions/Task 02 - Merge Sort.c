#include<stdio.h>

int arr[5] = {5, 9, 2366, 600, 3};

void mergesort(int start,int end)
{
    int mid = (start + end)/2;
    if(start == end) return;
    mergesort(start, mid);
    mergesort(mid+1, end);
    merge(start, mid, mid+1, end);
}

void merge(int start_one,int end_one,int start_two,int end_two)
{
    int temp[100], i = start_one, j = start_two, temp_ptr = 0;

    while (i != end_one+1 && j != end_two+1)
    {
        if (arr[i] > arr[j])
        {
            temp[temp_ptr] = arr[i];
            i++;
        }
        else
        {
            temp[temp_ptr] = arr[j];
            j++;
        }
        temp_ptr++;
    }
    if (i == end_one+1)
    {
        while (j != end_two+1)
        {
            temp[temp_ptr] = arr[j];
            j++;
            temp_ptr++;
        }
    }
    else
    {
        while (i != end_one+1)
        {
            temp[temp_ptr] = arr[i];
            i++;
            temp_ptr++;
        }
    }

    i = start_one;
    j = 0;
    while (i<=end_two)
    {
        arr[i] = temp[j];
        i++;
        j++;
    }
}

int main()
{
    int i;
    mergesort(0, 4);
    for (i=4; i>-1; i--) printf("%d ", arr[i]);
}
