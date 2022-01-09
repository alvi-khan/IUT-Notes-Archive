#include<stdio.h>
#include<string.h>

int main ()
{
    int n, i, j;
    scanf("%d", &n);
    char str[n][100];
    char temp[100];

    for (i=0; i<n; i++)                     //stores words in array
    {
        scanf("%s", &str[i]);
    }

    for (i=0; i<n; i++)                     //bubble sort
    {
        for (j=0; j<n; j++)
        {
            if ((strcmp(str[j], str[i])) == 1)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[i]);
                strcpy(str[i], temp);
            }
        }
    }

    for (i=n-1; i>=0; i--)                  //prints modified array
    {
        printf("%s\n", str[i]);
    }
}
