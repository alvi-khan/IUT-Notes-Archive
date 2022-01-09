#include<stdio.h>

int main()
{
    int i, j, num, a;

    printf("Number of integers to check: ");
    scanf("%d", &a);

    for (i=0; i<a; i++)
    {
        int res=0;
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num<=1)
        {
            res=1;
        }

        for (j=2; j<num; j++)
        {
            if ((num%j)==0)
            {
                res=1;
                break;
            }
        }
        if (res==0)
        {
            printf("%d is a prime number.\n", num);
        }
        else
        {
            printf("%d is not a prime number.\n", num);
        }
    }
}
