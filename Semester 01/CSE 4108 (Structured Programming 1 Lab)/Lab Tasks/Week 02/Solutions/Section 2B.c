#include <stdio.h>
int main()
{
    char arr[100];
    int ch=0, dg, i;
    for(i=0; i<6; i++)  scanf("%c", &arr[i]);

    for(int i=0; i<6; i++)
    {
        if(arr[i]>='A' && arr[i]<='Z')  ch++;
        if(arr[i]>='a' && arr[i]<='z')  ch++;
    }

    dg = 6 - ch;
    printf("Characters: %d\nDigits: %d", ch, dg);
}

