#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int i, flag = 0, j=0, k, a[100], x=1, y=1, l;
    FILE *fp1, *fp2;

    fp1 = fopen("output.txt", "w");                     //create output file
    if (fp1 == NULL)                                 //if file does not exist, print Error
        {
            printf("Error creating 'output.txt'");
            exit(1);
        }

    for (l=1; l<argc; l++)
    {
        fprintf(fp1, "\n\nFile #%d:\n\n", l);            //print file number
        fp2 = fopen(argv[l], "r");                       //open files one by one with read permission

        if (fp2 == NULL)                                 //if file does not exist, print Error
        {
            printf("Error opening %s", argv[i]);
            exit(1);
        }

        for ( ; ; )
        {
            i = fgetc(fp2);                              //i = each character of the current file in turn
            if (i == EOF)   break;                      //break loop if end of file reached
            else
            {
                while (i != 32 && i != 10)              //until a space or newline is reached,
                {
                    if (i<123 && i>64)   flag = 1;      //if alphabet is present
                    a[j] = i;                           //store value of i in array
                    j++;
                    i = fgetc(fp2);                      //gets next character
                    if (i == EOF)   break;              //if end of file reached, break
                }

                if (flag == 0)                          //if no alphabets present
                {
                    fprintf(fp1, "number #%d:\t", x);         //x is the current number
                    x++;
                }

                else
                {
                    fprintf(fp1, "word #%d:\t", y);           //y is the current word
                    y++;
                }

                for (k=0; k<j; k++)                     //print the array
                {
                    fprintf(fp1, "%c", a[k]);
                }
                fprintf(fp1, "\n");
                j=0;                                    //reset value of j and flag for next word in the file
                flag = 0;
            }
        }
        fclose(fp2);                                     //close the file
        x = 1;                                          //reset value of x and y for next file
        y = 1;
    }

    fclose(fp1);

}
