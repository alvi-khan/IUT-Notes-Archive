#ifndef STUDENT_H
#define STUDENT_H
#include"People.h"

class Student:public People
{
    public:
        Student(int v_sid, std::string v_dept);
        Student(std::string name, int age, int v_sid, std::string v_dept);

        int Getsid() { return sid; }
        void Setsid(int val) { sid = val; }
        std::string Getdept() { return dept; }
        void Setdept(std::string val) { dept = val; }
        void display();

    protected:

    private:
        int sid;
        std::string dept;
};

#endif // STUDENT_H
