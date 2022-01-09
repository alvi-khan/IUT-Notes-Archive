#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include <People.h>
using namespace std;


class Student : public People
{
    public:
        Student() : People(), sid(0), cgpa(0.0F), dept("") {};
        Student(string name, int age, int weight, int sid, float cgpa, string dept) : People(name, age, weight), sid(sid), cgpa(cgpa), dept(dept) {}
        int Getsid() { return sid; }
        void Setsid(int val) { sid = val; }
        float Getcgpa() { return cgpa; }
        void Setcgpa(float val) { cgpa = val; }
        string Getdept() { return dept; }
        void Setdept(string val) { dept = val; }
        void display();

    protected:

    private:
        int sid;
        float cgpa;
        string dept;
};

#endif // STUDENT_H
