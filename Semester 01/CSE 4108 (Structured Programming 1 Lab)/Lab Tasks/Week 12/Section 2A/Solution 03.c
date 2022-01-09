#include<stdio.h>
#include"mystring.h"

int main()
{
    //strconc will concatenate
    //strcopy will copy
    //strcomp will compare
    //strleng will give length
    //strulta will reverse

    char a[30][100] = {"el", "ppa", "gaz", "giz", "yru", "tnec", "noiti", "depxe", "ecnat", "sbus", "yras", "secen", "yrad", "noces", "ylt", "saeb", "evit", "necni", "noita", "vitom", "ES", "C", "s", "i", "eh", "t", "t", "seb", "tnem", "traped"};
    int i, j=0;
    char b[15][100];
    char temp[100];
    for (i=0; i<30; i++)
    {
        strconc(a[i], a[i+1]);      //joins every two strings
        strulta(a[i]);              //reverses the newly joint string
        strcopy(b[j], a[i]);        //stores new string in different array
        i++;
        j++;
    }

    for (i=0; i<15; i++)            //bubble sort array
    {
        for (j=0; j<i; j++)
        {
            if (strcomp(b[i], b[j]) == 1)
            {
                strcopy(temp, b[i]);
                strcopy(b[i], b[j]);
                strcopy(b[j], temp);
            }
        }
    }

    for (i=0; i<15; i++)            //print array
    {
        printf("%s\n", b[i]);
    }


}
