#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>        // for srand()
using namespace std;

string depts[6] = {"BSc CSE", "BSc EEE", "MSc CSE", "MSc EEE", "PhD CSE", "PhD EEE"};   // used to set department for Student
char special[32] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '?', '/', '`', '~', '-', '+', '_', '=', '[', ']', '{', '}', '\\', '|', '\"', '\'', ':', ';', '.', ',', '>', '<'};
// list of special characters for passwords

class Person
{
protected:                              // avoided creating getters and setters on purpose (even though everything should have them)
    string name;                        // not required to complete task and would make code messy since its one file and there are so many variables
    string contactNo;                   // best to store numbers in strings and parse them if needed (not needed here)
    char* password;
    string category;

    string passGen(int upper, int lower, int num, int spChar)       // password generator -> TASK 2
    {
        string pass;    // needs to be string so it can be shuffled
        srand(time(NULL) + rand());
        for (int i=0; i<upper; i++)     pass += rand() % 26 + 65;
        for (int i=0; i<lower; i++)     pass += rand() % 26 + 97;
        for (int i=0; i<num; i++)       pass += rand() % 10 + 48;
        for (int i=0; i<spChar; i++)    pass += special[rand() % 10];
        random_shuffle(pass.begin(), pass.end());   // shuffles the characters
        return  pass;
    }

    void displayMain()  // information for all child classes
    {
        cout<<string(50, '=')<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Category: "<<category<<endl;
        cout<<"Contact No.: "<<contactNo<<endl;
        cout<<"Password: "<<password<<endl;
    }

public:
    Person(string name = "", string contactNo = "", string category = ""): name(name), contactNo(contactNo), category(category)
    {
        password = new char[13];    // allocating memory
    }

    virtual ~Person()   // virtual because virtual functions are used elsewhere (best practice)
    {
        delete password;        // deleting memory
    }

    void setContactNo(string contact)   // setter and getter needed for addContactPrefix function
    {
        contactNo = contact;
    }

    string getContactNo()
    {
        return contactNo;
    }

    virtual void display() = 0;     // allows use for Person pointer array
};

class Student: virtual public Person    // virtual to avoid diamond problem with Staff_Student
{
protected:
    int studentID;          // assuming small numbers
    string program;

    void displayAdditional()    // information specific to Student
    {
        cout<<"Student ID: "<<studentID<<endl;
        cout<<"Program: "<<program<<endl;
    }
public:
    Student(string name = "", int studentID = -1, int program = -1, string contactNo = ""): Person(name, contactNo, "Student"), studentID(studentID), program(depts[program-1])
    {
        strcpy(password, passGen(5, 4, 1, 2).c_str());
    }
    void display()
    {
        displayMain();
        displayAdditional();
    }
};

class Staff: virtual public Person
{
protected:
    string joinDate;        // possible to use proper date format; seemed unnecessary here since only printing
    string designation;
    string dept;

    void displayAdditional()    // information specific to Staff
    {
        cout<<"Designation: "<<designation<<endl;
        cout<<"Department: "<<dept<<endl;
        cout<<"Joining Date: "<<joinDate<<endl;
    }
public:
    Staff(string name = "", string designation = "", string dept = "", string joinDate = "", string contactNo = ""): Person(name, contactNo, "Staff"), joinDate(joinDate), designation(designation), dept(dept)
    {
        strcpy(password, passGen(2, 5, 4, 1).c_str());
    }
    void display()
    {
        displayMain();
        displayAdditional();
    }
};

class Staff_Student: public Staff, public Student       // student password applies
{
private:
    float creditNo;
public:
    Staff_Student(string newName = "", int studentID = -1, int program = -1, string designation = "", string dept = "", string joinDate = "", string contact = "", float creditNo = -1.0): Student(newName, studentID, program, contact), Staff(newName, designation, dept, joinDate, contact), creditNo(creditNo)
    {
        category = "Staff-Student";
        name = newName;                 // does not work if set in initializer list; Student uses it and Staff overwrites it with default blank string
        contactNo = contact;
    }
    void display()
    {
        displayMain();
        Student::displayAdditional();
        Staff::displayAdditional();
        cout<<fixed<<setprecision(2)<<"Number of Credits: "<<creditNo<<endl;    // print credits to 2 decimal places
    }
};

void addContactPrefix(Person* person)                   // TASK 4
{
    string temp = person->getContactNo();
    if (temp[0] != '+')                         // assuming no invalid numbers (like +0171XXXXXXX)
    {
        string newContact = "+88" + temp;
        person->setContactNo(newContact);
    }
}

int main()
{
    Person* p[100];

    p[0] = new Student ("Abraham", 6, 1, "0110419201");
    p[1] = new Student ("Bruce", 7, 3, "0291118212");
    p[2] = new Student ("Chuck", 8, 5, "0381217223");
    p[3] = new Student ("Dwayne", 9, 2, "0471316234");
    p[4] = new Student ("Edward", 10, 3, "0561415245");
    p[5] = new Staff ("Frank", "Teacher", "CSE", "12/20/2019", "0534356446");
    p[6] = new Staff ("Gordon", "Laboratory Assistant", "EEE", "08/12/2018", "0633436437");
    p[7] = new Staff ("Hugh", "Teacher", "CSE", "10/15/2017", "0732437428");
    p[8] = new Staff ("Isaac", "Senior Teacher", "CSE", "07/03/2010", "0831438419");
    p[9] = new Staff ("Joe", "Department Head", "EEE", "12/10/2016", "0930439410");
    // TASK 3
    p[10] = new Staff_Student("Kobe", 1, 1, "Senior Teacher", "CSE", "12/12/2010", "055455611", 3.0);
    p[11] = new Staff_Student("Lionel", 2, 6, "Teacher", "EEE", "12/05/2010", "065356612", 1.5);
    p[12] = new Staff_Student("Malcolm", 3, 2, "Teacher", "EEE", "12/20/2010", "075257613", 2.5);
    p[13] = new Staff_Student("Nostradamus", 4, 1, "Senior Teacher", "CSE", "12/28/2010", "+88085158614", 4.0);
    p[14] = new Staff_Student("Oprah", 5, 5, "Teacher", "CSE", "12/02/2010", "095059615", 2.0);

    for (int i=0; i<15; i++)    p[i]->display();                // TASK 1

    cout<<string(50, '=')<<endl;
    cout<<string(17, ' ')<<"ADDING PREFIX..."<<endl;

    addContactPrefix(p[14]);    // this is changed
    addContactPrefix(p[13]);    // this is not changed

    p[14]->display();
    p[13]->display();

    for (int i=0; i<15; i++)    delete p[i];    // deleting pointers
}
