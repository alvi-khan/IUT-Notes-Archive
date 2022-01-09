#include<stdio.h>
#include<stdlib.h>

struct account              //structure for account information
{
    char name[100];
    int id;
    char type[8];
    float balance;
}add;

int main()
{
    int a, opt;
    FILE *fp;

    //INTERFACE
    printf("bankDB2B.txt");
    start:
    printf("\n\nChoose an option:\n1. View\n2. Add\n3. Exit\n\n");

    scanf("%d", &opt);

    if (opt == 1)
    {
        fp = fopen("bankDB2B.txt", "r");                 //open file in read mode

        if (fp == NULL)
        {
            printf("Error opening 'bankDB2B.txt'\n");    //error message
            exit(1);
        }

        for ( ; ; )                                         //print information from text file
        {
            a = fgetc(fp);
            if (a == EOF)   break;
            else    printf("%c", a);
        }

        fclose(fp);
    }

    else if(opt == 2)
    {
        fp = fopen("bankDB2B.txt", "a");                 //open file in append mode

        if (fp == NULL)                                     //error message
        {
            printf("Error opening 'bankDB2B.txt'\n");
            exit(1);
        }

        printf("Enter Name: ");                             //store information in structure
        getchar();
        gets(add.name);
        printf("\nEnter Account ID: ");
        scanf("%d", &add.id);
        printf("\nEnter Account Type: ");
        scanf("%s", &add.type);
        printf("\nEnter Balance: ");
        scanf("%f", &add.balance);
        fprintf(fp, "\n\n%s\n%d\n%s\n%0.2f", add.name, add.id, add.type, add.balance);
        //print to text file

        fclose(fp);
    }

    else if(opt == 3)
    {
        exit(1);
    }

    goto start;
}

