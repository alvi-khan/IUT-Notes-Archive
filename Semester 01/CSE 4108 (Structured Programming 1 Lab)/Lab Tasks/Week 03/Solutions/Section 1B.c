#include <stdio.h>
#include <string.h>

int main()
{
    int a, flag=0, j;
    scanf("%d", &a);
    getchar();
    int mark;
    for(int i=0; i<a; i++)
    {
        scanf("%d", &mark);
        if (mark == 2)  printf("Prime");                //unbelievable terrible method to check prime numbers
        else if (mark%2 == 0)   printf("Not Prime");
        else
        {
            for (j=3; j<mark; j++)
            {
                if(mark%j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                flag = 0;
                printf("Not Prime");
            }
            else    printf("Prime");
        }
    }

    return 0;
}
