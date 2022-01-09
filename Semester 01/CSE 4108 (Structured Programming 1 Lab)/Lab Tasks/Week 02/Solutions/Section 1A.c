#include <stdio.h>
int main()
{
    char ch[100];
    int al = 0, pc, i;
    for(int i=0; i<6; i++)  scanf("%c", &ch[i]);

    for(int i=0; i<6; i++)
    {
        if(ch[i]>='A' && ch[i]<='Z')  al++;
        if(ch[i]>='a' && ch[i]<='z')  al++;
    }
    pc = 6-al;

    printf("Alphabets: %d\nPunctuation: %d", al, pc);
}

