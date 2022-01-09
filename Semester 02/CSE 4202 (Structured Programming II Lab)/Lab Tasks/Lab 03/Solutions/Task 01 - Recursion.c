#include<stdio.h>
#include<string.h>

void reverse(char *start, char *end)
{
    if (start >= end)   return;
    char temp = start[0];
    start[0] = end[0];
    end[0] = temp;
    reverse(start+1, end-1);
}

int main()
{
    char string[100];
    printf("Enter string: ");
    scanf("%s", &string);
    reverse(&string, &string[strlen(string) - 1]);
    printf("Reverse String: %s", string);
}
