#include<stdio.h>
#include<stdlib.h>

struct dob                  //structure for date of birth
{
    char date[3];
    char month[3];
    char year[5];
};

struct student              //structure for student information
{
    char name[100];
    int id;
    struct dob birth_date;
    char dpt[4];
    float cgpa;
}add;

int main()
{
    int a, opt;
    FILE *fp;

    //INTERFACE
    printf("studentDB2A.txt");
    start:
    printf("\n\nChoose an option:\n1. View\n2. Add\n3. Exit\n\n");

    scanf("%d", &opt);

    if (opt == 1)
    {
        fp = fopen("studentDB2A.txt", "r");                 //open file in read mode

        if (fp == NULL)
        {
            printf("Error opening 'studentDB2A.txt'\n");    //error message
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
        fp = fopen("studentDB2A.txt", "a");                 //open file in append mode

        if (fp == NULL)                                     //error message
        {
            printf("Error opening 'studentDB1A.txt'\n");
            exit(1);
        }

        printf("Enter Name: ");                             //store information in structure
        getchar();
        gets(add.name);
        printf("\nEnter ID: ");
        scanf("%d", &add.id);
        printf("\nEnter Birth Date (dd mm yyyy): ");
        scanf("%s %s %s",&add.birth_date.date, &add.birth_date.month, &add.birth_date.year);
        printf("\nEnter Department (XXX): ");
        scanf("%s", &add.dpt);
        printf("\nEnter CGPA (X.XX): ");
        scanf("%f", &add.cgpa);
        fprintf(fp, "\n\n%s\n%d\n%s %s %s\n%s\n%0.2f", add.name, add.id, add.birth_date.date, add.birth_date.month, add.birth_date.year, add.dpt, add.cgpa);
        //print to text file

        fclose(fp);
    }

    else if(opt == 3)
    {
        exit(1);
    }

    goto start;
}
