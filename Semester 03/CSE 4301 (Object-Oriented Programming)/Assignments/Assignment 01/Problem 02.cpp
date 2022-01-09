#include<iostream>
using namespace std;

class Courses
{
    string courseTitle;
    float creditHours;
public:
    Courses() : courseTitle(""), creditHours(0.0F) {};
    void setCourseTitle(string newCourseTitle) {courseTitle = newCourseTitle;}
    string getCourseTitle() {return courseTitle;}
    void setCreditHours(float newCreditHours)
    {
        if (newCreditHours < 0)         creditHours = 0.0F;
        else if (newCreditHours > 4)    creditHours = 4.0F;
        else                            creditHours = newCreditHours;
    }
    float getCreditHours()  {return creditHours;}
};

class Departments
{
    Courses c[30];
public:
    void setCourseTitle(string newCourseTitle, int i) {c[i].setCourseTitle(newCourseTitle);}
    string getCourseTitle(int i) {return c[i].getCourseTitle();}
    void setCreditHours (float newCreditHours, int i) {c[i].setCreditHours(newCreditHours);}
    float getCreditHours (int i) {return c[i].getCreditHours();}
    float getTotalCreditHours()
    {
        float temp = 0.0F;
        for (int i=0; i<30; i++)    temp += c[i].getCreditHours();
        return temp;
    }
};

int main()
{
    Departments d;
    //d.setCreditHours(3.0, 5);
    //cout<<d.getCreditHours(5)<<endl;
    cout<<d.getTotalCreditHours();
}
