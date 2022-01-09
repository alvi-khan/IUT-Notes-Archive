#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int i, j, flag=0;
    char ch1, ch2;
    for (i=1; i<argc-1; i++)
    {
        for (j=i+1; j<argc; j++)
        {
            fp1 = fopen(argv[i], "r");          //open file 1 in read mode
            fp2 = fopen(argv[j], "r");          //open file 2 in read mode
            if (fp1 == NULL || fp2 == NULL)     //check if either file cannot be opened
            {
                printf("Error");
                exit(1);
            }
            while(!feof(fp1))                   //until the end of file 1 has been reached
            {
                ch1 = fgetc(fp1);               //get characters of file 1 one at a time
                ch2 = fgetc(fp2);               //get characters of file 2 one at a time
                if (ch1 != ch2)                 //if characters differ, flag = 1
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)                      //if flag = 1, not identical and reset flag
            {
                flag = 0;
                printf("%s and %s are not identical.\n", argv[i], argv[j]);
            }
            else    printf("%s and %s are identical.\n", argv[i], argv[j]);

            fclose(fp1);
            fclose(fp2);
        }
    }
}
