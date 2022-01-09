#ifndef TEACHER_H
#define TEACHER_H
#include<string>
#include <People.h>
using namespace std;

class Teacher : public People
{
    public:
        Teacher() : People(), dept(""), room(0), phone(0) {}
        Teacher(string name, int age, int weight, string dept, int room, int phone) : People(name, age, weight), dept(dept), room(room), phone(phone) {}
        string Getdept() { return dept; }
        void Setdept(string val) { dept = val; }
        int Getroom() { return room; }
        void Setroom(int val) { room = val; }
        int Getphone() { return phone; }
        void Setphone(int val) { phone = val; }
        void display();

    protected:

    private:
        string dept;
        int room;
        int phone;
};

#endif // TEACHER_H
