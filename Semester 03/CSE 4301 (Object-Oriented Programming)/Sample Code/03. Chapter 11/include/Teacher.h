#ifndef TEACHER_H
#define TEACHER_H
#include"People.h"

class Teacher:public People
{
    public:
        Teacher(int v_tid, std::string v_dept);
        Teacher(std::string name,int age,int v_tid, std::string v_dept);

        int Gettid() { return tid; }
        void Settid(int val) { tid = val; }
        std::string Getdept() { return dept; }
        void Setdept(std::string val) { dept = val; }
        void display();
    protected:

    private:
        int tid;
        std::string dept;
};

#endif // TEACHER_H
