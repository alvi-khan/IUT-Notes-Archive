#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char ch;

    fp = fopen("text1.txt", "r");                       //open text1 in read mode
    if (fp == NULL)
    {
        printf("Error opening 'text1.txt'.");           //error message
        exit(1);
    }
    printf("text1.txt\n");
    for ( ; ; )                                         //print contents of text1
    {
        ch = fgetc(fp);
        if (ch == EOF) break;
        else            printf("%c", ch);
    }
    printf("\n");
    fclose(fp);

    fp = fopen("text2.txt", "r");                       //open text2 in read mode
    if (fp == NULL)
    {
        printf("Error opening 'text2.txt'.");           //error message
        exit(1);
    }
    printf("text2.txt\n");
    for ( ; ; )                                         //print contents of text2
    {
        ch = fgetc(fp);
        if (ch == EOF) break;
        else            printf("%c", ch);
    }
    fclose(fp);
}
