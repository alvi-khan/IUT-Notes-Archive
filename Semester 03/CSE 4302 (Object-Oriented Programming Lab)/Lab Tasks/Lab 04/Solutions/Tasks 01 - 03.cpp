#include<iostream>
#include<ctime>
using namespace std;

class Student
{
    string name;
    int dobDate;
    int dobMonth;
    int dobYear;
    int id;
    float cgpa;

public:
    void setInfo(string sname, int sdate, int smonth, int syear, int sid, float cg)
    {
        name = sname;
        dobDate = sdate;
        dobMonth = smonth;
        dobYear = syear;
        id = sid;
        cgpa = cg;
    }
    void getInfo()
    {
        cout<<"Student Name: "<<name<<endl;
        cout<<"Date of Birth: "<<dobDate<<"/"<<dobMonth<<"/"<<dobYear<<endl;
        cout<<"Student ID: "<<id<<endl;
        printf("CGPA: %0.2f\n", cgpa);
    }
    Student() : name({'\0'}), dobDate(0), dobMonth(0), dobYear(0), id(0), cgpa(0.00)
    {}

    void getAge(int cdate, int cmonth, int cyear)   //manual date age finder
    {
        int ageYear = cyear - dobYear;
        if (ageYear <= 0)   cout<<endl<<"Error. Date of birth is after current date."<<endl;
        else                cout<<endl<<"Age is: "<<ageYear<<" years"<<endl;
    }

    void getAge()       //auto date age finder
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int ageYear = (ltm->tm_year) +1910 - dobYear;
        if (ageYear <= 0)   cout<<endl<<"Error.Date of birth is after current date."<<endl;
        else                cout<<endl<<"Age is: "<<ageYear<<" years"<<endl;
    }
};

void calculateAge(Student s)
{
    int cdate, cmonth, cyear;
    cout<<endl<<"Enter current date (dd): ";
    cin>>cdate;
    cout<<endl<<"Enter current month (mm): ";
    cin>>cmonth;
    cout<<endl<<"Enter current year (yyyy): ";
    cin>>cyear;

    s.getAge(cdate, cmonth, cyear);
}

int main()
{
    cout<<"Task 1:"<<endl;
    Student s1;
    s1.setInfo("A", 1, 7, 1992, 24, 3.00);
    s1.getInfo();
    cout<<endl<<"Task 2:"<<endl;
    calculateAge(s1);
    cout<<endl<<"Task 3:"<<endl;
    s1.getAge();
}
