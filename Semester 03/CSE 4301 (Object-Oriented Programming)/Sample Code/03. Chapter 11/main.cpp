#include <iostream>
#include"People.h"
#include"Student.h"
#include"Teacher.h"
using namespace std;


void testPeopleClass()
{
    People p[]={{"Rahim",30},{"Karima",20}};
    p[0].display();
    p[1].display();

    People *ptr[3];

    for(int i=0;i<3;i++)
        ptr[i]=new People("John Doe",i*10);

    for(int i=0;i<3;i++)
        ptr[i]->display();

    for(int i=0;i<3;i++)
        delete ptr[i];

}

void testStudentClass()
{
    Student *ptr[3];

    ptr[0]=new Student("Rahima",22,101,"CSE");
    ptr[1]=new Student("Rahim",23,102,"CSE");
    ptr[2]=new Student("Jamal",25,201,"EEE");

    for(int i=0;i<3;i++)
    {
        if(i%2)ptr[i]->display();
        else ptr[i]->People::display();

    }
    for(int i=0;i<3;i++)
        delete ptr[i];
}


void testTeacherClass()
{
    Teacher *ptr[3];

    ptr[0]=new Teacher("Rahima",22,101,"CSE");
    ptr[1]=new Teacher("Rahim",23,102,"CSE");
    ptr[2]=new Teacher("Jamal",25,201,"EEE");

    for(int i=0;i<3;i++)
    {
        if(i%2)ptr[i]->display();
        else ptr[i]->People::display();

    }
    for(int i=0;i<3;i++)
        delete ptr[i];
}

void testBaseClassPointer()
{
    People *ptr[3];
    ptr[0]=new People("Rahima",22);
    ptr[1]=new Student("Rahim",23,102,"CSE");
    ptr[2]=new Teacher("Jamal",25,201,"EEE");

    for(int i=0;i<3;i++)
    {
        ptr[i]->display();
    }
    for(int i=0;i<3;i++)
        delete ptr[i];

}

int main()
{
    //testPeopleClass();
    //testStudentClass();
    //testTeacherClass();
    testBaseClassPointer();
}
