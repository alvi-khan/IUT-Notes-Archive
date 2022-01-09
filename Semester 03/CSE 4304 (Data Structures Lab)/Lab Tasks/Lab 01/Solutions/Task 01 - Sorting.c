#include<stdio.h>

int main()
{
    int arr[1000], i=0, j, k, temp, temp1, countInst=0;
    int numbers[1000], count[1000];

    while(scanf("%d", &arr[i]))//taking input
    {
        if (arr[i] > 0) i++;
        else            break;
    }

    for (j=0; j<i; j++) //bubble sort
    {
        for (k=0; k<j; k++)
        {
            if (arr[j]<arr[k])
            {
                temp = arr[j];
                arr[j]=arr[k];
                arr[k]=temp;
            }
        }
    }

    //for (j=0; j<i; j++) printf("%d", arr[j]);

    k=0;
    for (j=0; j<i; j++)
    {
        numbers[k] = arr[j];

        while (arr[j+1] == arr[j])
        {
            countInst++;
            j++;
        }
        countInst++;

        count[k] = countInst;

        countInst = 0;
        k++;
    }

    for (j=0; j<k; j++) //bubble sort
    {
        for (i=0; i<j; i++)
        {
            if (count[j]>count[i])
            {
                temp = count[j];
                temp1 = numbers[j];
                count[j]=count[i];
                numbers[j]=numbers[i];
                count[i]=temp;
                numbers[i]=temp1;
            }
        }
    }

    for (j=0; j<k; j++) printf("%d occurs: %d times\n", numbers[j], count[j]);
}

