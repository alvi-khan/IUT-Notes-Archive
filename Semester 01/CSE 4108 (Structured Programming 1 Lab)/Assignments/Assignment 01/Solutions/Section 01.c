#include<stdio.h>
#include<string.h>

int main()
{
    int a, i, j, cons=0, vow=0;
    /* Assuming the string will only contain alphabets and consonants*/

    printf("Enter the number of strings: ");
    scanf("%d", &a);

    char str[100];
    /* Assuming the string will be limited to 100 characters */

    for (i=0; i<a; i++)
    {
        printf("\nPlease enter a string: \n");
        scanf("%s", &str);
        int len = strlen(str);

        for (j=0; j<len; j++)
        {
            if ((str[j]=='a')||(str[j]=='e')||(str[j]=='i')||(str[j]=='o')||(str[j]=='u')||(str[j]=='A')||(str[j]=='E')||(str[j]=='I')||(str[j]=='O')||(str[j]=='U'))
            {
                vow++;
            }
            else
            {
                cons++;
            }
        }
    }

    printf("\nConsonants: %d", cons);
    printf("\nVowels: %d", vow);
}
