#include "Student.h"

Student::Student(int v_sid, std::string v_dept):sid(v_sid),dept(v_dept),People("John Doe", 20)
{
    //ctor
}
Student::Student(std::string name, int age, int v_sid, std::string v_dept):sid(v_sid),dept(v_dept),People(name,age)
{
    //ctor
}

void Student::display()
{
    std::cout<<"Student "<<Getname()<<" has id "<<sid<<" from "<<dept<<std::endl;
}
