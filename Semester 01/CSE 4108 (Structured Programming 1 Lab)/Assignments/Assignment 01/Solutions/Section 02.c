#include<stdio.h>
#include<string.h>

int main()
{
    int a, i, j, alph=0, dig=0;
    /* Assuming the string will only contain alphabets and digits */

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
            if ((str[j]=='1')||(str[j]=='2')||(str[j]=='3')||(str[j]=='4')||(str[j]=='5')||(str[j]=='6')||(str[j]=='7')||(str[j]=='8')||(str[j]=='9')||(str[j]=='0'))
            {
                dig++;
            }
            else
            {
                alph++;
            }
        }
    }

    printf("\nAlphabets: %d", alph);
    printf("\nDigits: %d", dig);
}
