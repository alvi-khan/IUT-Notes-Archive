#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    scanf("%d", &a);
    getchar();
    char ch[100];
    int alphabets = 0, digits = 0;
    for(int i=0; i<a; i++)
    {
        gets(ch);
        int s = strlen(ch);
        for(int j=0; j<s; j++)
        {
            if(ch[j]<='Z' && ch[j]>='A' || ch[j]<='z' && ch[j]>='a')  alphabets = alphabets + 1;
            else    digits = digits + 1;
        }
    }
    printf("alphabets: %d digits: %d", alphabets, digits);

    return 0;
}
