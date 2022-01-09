#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    scanf("%d", &a);
    getchar();
    char ch[100];
    int vowel = 0, consonant = 0;
    for(int i=0; i<a; i++)
    {
        gets(ch);
        int s = strlen(ch);
        for(int j=0; j<s; j++)
        {
            if(ch[j]<='Z' && ch[j]>='A')  ch[j] = ch[j] + ('a'-'A');
            if((ch[j]<='9' && ch[j]>='0'))
            {
                if(ch[j]=='a' || ch[j]=='e' || ch[j]=='i' || ch[j]=='o' || ch[j]=='u')
                {
                    vowel = vowel + 1;
                }
                else    consonant = consonant + 1;
            }
        }
    }
    printf("vowel count: %d consonant count: %d", vowel, consonant);

    return 0;
}
