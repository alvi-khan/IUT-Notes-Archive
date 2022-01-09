#include<stdio.h>

int main(int argc, char *argv[])
{
    int i, flag = 0, j=0, k, a[100], x=1, y=1, l;
    FILE *fp;
    for (l=1; l<argc; l++)
    {
        printf("\n\nFile #%d:\n\n", l);                 //print file number
        fp = fopen(argv[l], "r");                       //open files one by one with read permission

        if (fp == NULL)                                 //if file does not exist, print Error
        {
            printf("Error");
            exit(1);
        }

        for ( ; ; )
        {
            i = fgetc(fp);                              //i = each character of the current file in turn
            if (i == EOF)   break;                      //break loop if end of file reached
            else
            {
                while (i != 32 && i != 10)              //until a space or newline is reached,
                {
                    if (i<123 && i>64)   flag = 1;      //if alphabet is present
                    a[j] = i;                           //store value of i in array
                    j++;
                    i = fgetc(fp);                      //gets next character
                    if (i == EOF)   break;              //if end of file reached, break
                }

                if (flag == 0)                          //if no alphabets present
                {
                    printf("number #%d:\t", x);         //x is the current number
                    x++;
                }

                else
                {
                    printf("word #%d:\t", y);           //y is the current word
                    y++;
                }

                for (k=0; k<j; k++)                     //print the array
                {
                    printf("%c", a[k]);
                }
                printf("\n");
                j=0;                                    //reset value of j and flag for next word in the file
                flag = 0;
            }
        }
        fclose(fp);                                     //close the file
        x = 1;                                          //reset value of x and y for next file
        y = 1;
    }

}
