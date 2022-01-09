#include<stdio.h>

struct dob
{
    int date;
    char month[13];
    int year;
};

struct student
{
    char name[100];
    int id;
    struct dob birth_date;
    char add[100];
    char dpt[4];
    float cgpa;
    struct student *ptr[3];
} a1, a2, a3, a4;

int main()
{
    struct student a1 = {"A", 15, 09, "May", 1999, "E", "CSE", 0.00};
    struct student a2 = {"B", 13, 13, "June", 1999, "F", "CSE", 0.00};
    struct student a3 = {"C", 27, 05, "July", 1999, "G", "CSE", 0.00};
    struct student a4 = {"D", 06, 17, "August", 1999, "H", "CSE", 0.00};
    a1.ptr[0] = &a2, a1.ptr[1] = &a3, a1.ptr[2] = &a4;
    a2.ptr[0] = &a1, a2.ptr[1] = &a3, a2.ptr[2] = &a4;
    a3.ptr[0] = &a1, a3.ptr[1] = &a2, a3.ptr[2] = &a4;
    a4.ptr[0] = &a1, a4.ptr[1] = &a2, a4.ptr[2] = &a3;

    char name[100];
    struct student b;

    input:
    printf("Please enter student name: ");
    scanf("%s", &name);
    printf("\n");


    if (strcmp(name, "a") == 0)  b = a1;
    else if (strcmp(name, "b") == 0)  b = a2;
    else if (strcmp(name, "c") == 0)  b = a3;
    else if (strcmp(name, "d") == 0)  b = a4;
    else
    {
        printf("Invalid input\n");
        goto input;
    }

    printf("\t\t%s %d %d %s, %d %s %s %.02f", b.name, b.id, b.birth_date.date, b.birth_date.month, b.birth_date.year, b.add, b.dpt, b.cgpa);

    int i;
    for (i=0; i<3; i++)
    {
        printf("\nRoommate %d:\t%s %d %d %s, %d %s %s %.02f", i+1, b.ptr[i]->name, b.ptr[i]->id, b.ptr[i]->birth_date.date, b.ptr[i]->birth_date.month, b.ptr[i]->birth_date.year, b.ptr[i]->add, b.ptr[i]->dpt, b.ptr[i]->cgpa);
    }
    printf("\n\n");
    goto input;
}
