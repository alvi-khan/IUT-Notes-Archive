#include<stdio.h>

union desg                  //union for designation
{
    int post_num;
    char post_name[100];
};

union mon                   //union for month
{
    int mon_num;
    char mon_name[100];
};

struct date_of_birth        //structure for date of birth
{
    int date;
    union mon month;
    int year;
};

struct add                  //structure for address
{
    int flat;
    int house;
    int road;
    char area[100];
    char district[100];
    char country[100];
};

union type                  //union for account type
{
    int acc_type_num;
    char acc_type_name[100];
};

struct account              //structure for account
{
    char name[100];
    union desg designation;
    struct date_of_birth dob;
    struct add address;
    char number[100];
    union type acctype;
    float balance;
    struct account *ptr;
};

int main()
{
    char designations[5][100] = {"Student", "Lecturer", "Associate Professor", "Assistant Professor", "Professor"};
    char accounts[2][100] = {"Savings", "Current"};
    char months[12][100] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //information for unions are stored in the above arrays so they can be called as required

    struct account a1 = {"A", "Lecturer", 07, "February", 1992, 105, 25, 13, "Dhanmondi", "Dhaka", "Bangladesh", "+880**********", "Savings", 1340022.75};
    struct account a2 = {"B", 02, 02, 03, 1997, 3, 11, 9, "Dhanmondi", "Dhaka", "Bangladesh", "+880**********", 02, 1349987.60};
    a1.ptr = &a2;
    a2.ptr = &a1;

    printf("%s\n", a1.name);

    if(a1.designation.post_num<10)  printf("%s\n", designations[a1.designation.post_num - 1]);
    else                            printf("%s\n", a1.designation);

    //for each of the unions, if the value is less the 10, then the input is counted as an integer. else it is counted as a string

    printf("%d ", a1.dob.date);

    if(a1.dob.month.mon_num<10)     printf("%s, ", months[a1.dob.month.mon_num - 1]);
    else                            printf("%s, ", a1.dob.month);

    printf("%d\nFlat: %d, House: %d, Road: %d, %s, %s, %s\n%s\n", a1.dob.year, a1.address.flat, a1.address.house, a1.address.road, a1.address.area, a1.address.district, a1.address.country, a1.number);

    if(a1.acctype.acc_type_num<10)  printf("%s\n", accounts[a1.acctype.acc_type_num - 1]);
    else                            printf("%s\n", a1.acctype);

    printf("%0.2f", a1.balance);

    printf("\n\nReference:\n\n");

    printf("%s\n", a1.ptr->name);

    if(a1.ptr->designation.post_num<10)  printf("%s\n", designations[a1.ptr->designation.post_num - 1]);
    else                            printf("%s\n", a1.ptr->designation);

    printf("%d ", a1.ptr->dob.date);

    if(a1.ptr->dob.month.mon_num<10)     printf("%s, ", months[a1.ptr->dob.month.mon_num - 1]);
    else                            printf("%s, ", a1.ptr->dob.month);

    printf("%d\nFlat: %d, House: %d, Road: %d, %s, %s, %s\n%s\n", a1.ptr->dob.year, a1.ptr->address.flat, a1.ptr->address.house, a1.ptr->address.road, a1.ptr->address.area, a1.ptr->address.district, a1.ptr->address.country, a1.ptr->number);

    if(a1.ptr->acctype.acc_type_num<10)  printf("%s\n", accounts[a1.ptr->acctype.acc_type_num - 1]);
    else                            printf("%s\n", a1.ptr->acctype);

    printf("%0.2f", a1.ptr->balance);
}
