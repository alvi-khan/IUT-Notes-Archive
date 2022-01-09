#ifndef PEOPLE_H
#define PEOPLE_H
#include<string>
using namespace std;


class People
{
    public:
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        int Getage() { return age; }
        void Setage(int val) { age = val; }
        int Getweight() {return weight;}
        void SetWeight(int val) {weight = val;}
        void display();
        People() : name(""), age(0), weight(0) {}
        People(string name, int age, int weight) : name(name), age(age), weight(weight) {}

    protected:

    private:
        string name;
        int age;
        int weight;
};

#endif // PEOPLE_H
