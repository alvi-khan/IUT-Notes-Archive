#ifndef PEOPLE_H
#define PEOPLE_H

#include<iostream>
#include<string>

class People
{
    public:
        People(std::string v_name, int v_age);

        std::string Getname() { return name; }
        void Setname(std::string val) { name = val; }
        int Getage() { return age; }
        void Setage(int val) { age = val; }
        void display();
    protected:

    private:
        std::string name;
        int age;
};

#endif // PEOPLE_H
