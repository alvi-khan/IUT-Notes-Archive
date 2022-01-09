#include "Teacher.h"

Teacher::Teacher(int v_tid, std::string v_dept):tid(v_tid),dept(v_dept),People("TEACHER",30)
{
    //ctor
}
Teacher::Teacher(std::string name,int age, int v_tid, std::string v_dept):tid(v_tid),dept(v_dept),People(name,age)
{
    //ctor
}
void Teacher::display()
{
    std::cout<<Getname()<<" sir is with "<<dept<<" department"<<std::endl;
}
