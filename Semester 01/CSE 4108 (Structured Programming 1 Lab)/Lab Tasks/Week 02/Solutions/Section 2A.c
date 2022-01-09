#include <stdio.h>
int main()
{
    char ch[100];
    int uc=0, lc, i;
    for(i=0; i<5; i++)  scanf("%c", &ch[i]);

    for(int i=0; i<5; i++)  if(ch[i]>='A' && ch[i]<='Z')  uc++;
    lc = 5-uc;
    printf("Upper Case: %d\nLower Case: %d", uc, lc);
}

