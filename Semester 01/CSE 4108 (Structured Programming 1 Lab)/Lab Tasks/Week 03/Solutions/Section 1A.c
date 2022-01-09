#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    scanf("%d", &a);
    getchar();
    int mark;
    for(int i=0; i<a; i++)
    {
        scanf("%d", &mark);
        if (mark>80)    printf("A+");
        else if (mark>75)   printf("A");
        else if (mark>70)   printf("A-");
        else if (mark>65)   printf("B+");
        else if (mark>60)   printf("B");
        else if (mark>40)   printf("D");
        else                printf("F");
    }

    return 0;
}
