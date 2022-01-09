#include<stdio.h>

int main()
{
    char str[100];
    scanf("%s", &str);

    int len = strlen(str);
    int a, i, flag=0;

    if (len%2 == 0) a=len/2;
    else            a=(len/2)+1;

    for (i=0; i<a; i++)
    {
        if(str[i] != str[len-1-i])  flag = 1;
    }

    if(flag == 1)   printf("Not Palindrome");
    else            printf("Palindrome");
}
