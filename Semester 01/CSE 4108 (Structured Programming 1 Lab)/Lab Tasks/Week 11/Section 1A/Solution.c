#include<stdio.h>
#include<stdlib.h>

struct dob                              //structure for date of birth
{
    char date[3];
    char month[3];
    char year[5];
};

struct teacher                          //structure for teacher information
{
    char name[100];
    char position[100];
    struct dob birth_date;
    char dpt[4];
    float credits;
    char spz[100];
}add;

int main()
{
    int opt;
    FILE *fp;
    char ch;
    //INTERFACE
    printf("teacherDB1A.txt");
    start:
    printf("\n\nChoose an option:\n1. View\n2. Add\n3. Exit\n\n");

    scanf("%d", &opt);

    if (opt == 1)
    {
        fp = fopen("teacherDB1A.txt", "r");                     //open file in read mode

        if (fp == NULL)                                         //error message
        {
            printf("Error opening 'teacherDB2A.txt'\n");
            exit(1);
        }

        for ( ; ; )                                             //print information from text file
        {
            ch = fgetc(fp);
            if (ch == EOF)   break;
            else    printf("%c", ch);
        }

        fclose(fp);
    }

    else if(opt == 2)
    {
        fp = fopen("teacherDB1A.txt", "a");                     //open file in append mode

        if (fp == NULL)                                         //error message
        {
            printf("Error opening 'teacherDB2A.txt'\n");
            exit(1);
        }

        printf("Enter Name: ");                                 //store information in structure
        getchar();
        gets(add.name);
        printf("\nEnter Position: ");
        gets(add.position);
        printf("\nEnter Birth Date (dd mm yyyy): ");
        scanf("%s %s %s",&add.birth_date.date, &add.birth_date.month, &add.birth_date.year);
        printf("\nEnter Department (XXX): ");
        scanf("%s", &add.dpt);
        printf("\nEnter Credits (XX.X): ");
        scanf("%f", &add.credits);
        printf("\nEnter Specialization: ");
        getchar();
        gets(add.spz);
        fprintf(fp, "\n\n%s\n%s\n%s %s %s\n%s\n%0.1f\n%s", add.name, add.position, add.birth_date.date, add.birth_date.month, add.birth_date.year, add.dpt, add.credits, add.spz);
        //print to text file

        fclose(fp);
    }

    else if(opt == 3)
    {
        exit(1);
    }

    goto start;
}
