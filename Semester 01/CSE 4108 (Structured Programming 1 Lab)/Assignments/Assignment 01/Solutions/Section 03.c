#include<stdio.h>

int main()
{
    int a, i;
    double sum;

    /* Taking number of subjects as input */
    printf("Please input the number of subjects and press enter: ");
    scanf("%d", &a);

    printf("\nPlease input score for each subject and press enter:\n\n");

    for (i=0; i<a; i++)
    {
        /* Taking score of each subject in turn as input */
        int n;
        scanf("%d", &n);

        if ((n<0)||(n>100))
        {
            printf("Error: The score must be between 0 and 100.\nPlease enter the score again.\n");
            i--;
            continue;
        }
        /* Printing grade of each subject directly below score */
        if (n<40)
        {
            printf("F\n\n");
        }
        else if (n<60)
        {
            printf("D\n\n");
            sum=sum+1;
        }
        else if (n<65)
        {
            printf("B\n\n");
            sum=sum+2;
        }
        else if (n<70)
        {
            printf("B+\n\n");
            sum=sum+2.5;
        }
        else if (n<75)
        {
            printf("A-\n\n");
            sum=sum+3;
        }
        else if (n<80)
        {
            printf("A\n\n");
            sum=sum+3.5;
        }
        else
        {
            printf("A+\n\n");
            sum=sum+4;
        }

    }
    double m = (double) a;
    double res = sum/a;
    printf("CGPA: %0.2f", res);
}
