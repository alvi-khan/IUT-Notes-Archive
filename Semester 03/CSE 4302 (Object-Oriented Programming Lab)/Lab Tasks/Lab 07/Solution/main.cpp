#include <iostream>
#include <People.h>
#include <Student.h>
#include <Teacher.h>

using namespace std;

void searchByID(Student s[], int n, int id)
{
    for (int i=0; i<n; i++)
    {
        if (s[i].Getsid() == id)
        {
            s[i].display();
            return;
        }
    }
    cout<<"Student not found."<<endl;
}

void searchStudentByName(Student s[], int n, string name)
{
    for (int i=0; i<n; i++)
    {
        if (s[i].Getname() == name)
        {
            s[i].display();
            return;
        }
    }
    cout<<"Student not found."<<endl;
}

void searchTeacherByName(Teacher t[], int n, string name)
{
    for (int i=0; i<n; i++)
    {
        if (t[i].Getname() == name)
        {
            t[i].display();
            return;
        }
    }
    cout<<"Teacher not found."<<endl;
}

void displayDept (Student s[], Teacher t[], int n, string dept)
{
    cout<<"Students: "<<endl;
    for (int i=0; i<n; i++) if (s[i].Getdept() == dept) s[i].display();

    cout<<endl<<"Teachers: "<<endl;
    for (int i=0; i<n; i++) if (t[i].Getdept() == dept) t[i].display();
    cout<<endl;
}

int main()
{
    cout<<"Task 1:"<<endl;
    People p1("A", 21, 60);
    p1.display();
    cout<<endl;
    Student s1("A", 21, 60, 25, 3.75, "CSE");
    s1.display();
    cout<<endl;
    Teacher t1("A", 21, 60, "CSE", 120, 0101);
    t1.display();
    cout<<endl<<endl;

    cout<<"Task 2: "<<endl;
    int n = 3;
    Student s[n];
    Teacher t[n];
    for (int i=0; i<n; i++)
    {
        s[i].Setage(i);
        s[i].SetWeight(i);
        s[i].Setsid(i);
        s[i].Setcgpa(i);
        t[i].Setage(i);
        t[i].SetWeight(i);
        t[i].Setroom(i);
        t[i].Setphone(i);
    }
    s[0].Setname("A");
    s[1].Setname("B");
    s[2].Setname("C");
    s[0].Setdept("EEE");
    s[1].Setdept("B");
    s[2].Setdept("EEE");
    t[0].Setname("D");
    t[1].Setname("E");
    t[2].Setname("F");
    t[0].Setdept("D");
    t[1].Setdept("EEE");
    t[2].Setdept("F");

    searchByID(s, n, 1);
    cout<<endl;
    searchStudentByName(s, n, "B");
    cout<<endl;
    searchTeacherByName(t, n, "D");
    cout<<endl;
    displayDept(s, t, n, "EEE");
}
