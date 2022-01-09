#include<stdio.h>

//for each function, when a string is passed to it, the character point (say char *a) points to the first character of that string. So if the value of the pointer is incremented (a++), it points to each character in turn.

void strconc(char *a, char *b)
{
    while(*a != '\0')
    {
        a++;                //get to the null character
    }

    while(*b != '\0')
    {
        *a = *b;            //put each character from b into a, starting from the null character in a
        a++;
        b++;
    }
}

void strcopy(char *a, char *b)
{
    while(*b != '\0')
    {
        *a = *b;                //just replace each character of a with b
        a++;
        b++;
    }
    *a = '\0';                  //puts a null character at the end to end the string in case b was shorter than a
}

int strcomp(char *a, char*b)
{
    int flag = 0;
    while((*a != '\0') && (*b != '\0'))  //loop until a null character is reached
    {

        if (*a > *b)
        {
            flag = -1;
        }
        else if (*a < *b)
        {
            flag = 1;
        }

        if (flag != 0 ) break;

        a++;
        b++;
    }
    a++;
    b++;

    if (*a != '\0' && flag == 0) flag = 1;      //if end of either string has not been reached and both were the same till now, give values so that longer strings are after shorter ones
    else if(*b != '\0' && flag == 0) flag = -1;

    return flag;
}

int strleng(char *a)
{
    int i = 0;
    while(*a != '\0')           //keep counting until the null character is reached
    {
        i++;
        a++;
    }
    return i;
}

void strulta(char *a)
{
    char b[100];
    int i =0, j=0;
    while(*a != '\0')           //copy entire string into new array
    {
        b[i] = *a;
        a++;
        i++;
    }
    a--;
    while(j<=i)             //replace values of string from array going backwards
    {
        *a = b[j];
        a--;
        j++;
    }
}

int main()
{
    char a[100] = "Hello";
    char b[100] = "World";


    strconc(a, b);
    printf("Concatenated 'Hello' and 'World': %s\n", a);

    char c[100] = "Hello";
    char d[100] = "Wor";

    strcopy(c, d);
    printf("Copied 'Wor' into 'Hello': %s\n", c);

    char e[100] = "a";
    char f[100] = "b";

    printf("Compared 'a' and 'b': %d\n", strcomp(e, f));

    char g[100] = "Hello";

    printf("Length of 'Hello': %d\n", strleng(g));

    char h[100] = "Hello";
    strulta(h);
    printf("Reversed 'Hello': %s", h);

}
