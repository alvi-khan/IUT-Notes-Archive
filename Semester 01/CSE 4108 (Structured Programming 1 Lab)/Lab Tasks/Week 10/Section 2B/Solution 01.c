#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int i, j;
    for (i=1; i<argc; i++)
    {
        printf("File %d:\n", i);                //prints the file number
        fp = fopen(argv[i], "r");               //opens each file in read mode

        if (fp == NULL)                         //if file does not exists, print error and exit program
        {
            printf("Error");
            exit(1);
        }

        for ( ; ; )
        {
            j = fgetc(fp);                      //get each character from the file
            if (j == EOF)  break;               //break loop if end of file reached
            else            printf("%c", j);    //print each character
        }
        printf("\n");
    }
}
