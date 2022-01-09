#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int i;
    char ch;

    fp1 = fopen(argv[argc-1], "w");                 //open output file in write mode
    if (fp1 == NULL)                                //error message
    {
        printf("Error opening output file.");
        exit(1);
    }

    for (i=1; i<argc-1; i++)                        //loop through each input file
    {
        fp2 = fopen(argv[i], "r");                  //open input file in read mode
        if (fp2 == NULL)                            //error message
        {
            printf("Error opening %s", argv[i]);
            exit(1);
        }

        for ( ; ; )                                 //print information from file to output file
        {
            ch = fgetc(fp2);
            if (ch == EOF)  break;
            else    fprintf(fp1, "%c", ch);
        }

        if (i!=argc-1)  fprintf(fp1, "\n");
        fclose(fp2);
    }

    fclose(fp1);
}
