#include <stdio.h>
int main()
{
    char ch[100];
    int lc=0, dg, i;
    for(int i=0; i<6; i++)  scanf("%c", &ch[i]);

    for(int i=0; i<6; i++)  if(ch[i]>='a' && ch[i]<='z')  lc++;
    dg = 6 - lc;

    printf("Lower Case: %d\nDigits: %d", lc, dg);
}

