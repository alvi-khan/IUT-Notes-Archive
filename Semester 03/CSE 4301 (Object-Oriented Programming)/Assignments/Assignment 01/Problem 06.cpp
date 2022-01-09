#include<iostream>
#include<string.h>
using namespace std;
#define MAX_LEN 500

class myString
{
    char *characterString = new char [MAX_LEN];
public:
    char * operator + (myString s)
    {
        if ((sizeof(characterString)/sizeof(char)) + (sizeof(s.characterString)/sizeof(char)) > MAX_LEN)
        {
            cout<<"Exceeds maximum length.\n";
            return characterString;
        }
        else
        {
            char *result = new char [MAX_LEN];
            result = strcpy(result, characterString);
            result = strcat(result, s.characterString);
            return result;
        }
    }

    void operator = (char* s){characterString = s;}

    void operator += (myString s)
    {
        if ((sizeof(characterString)/sizeof(char)) + (sizeof(s.characterString)/sizeof(char)) > MAX_LEN)
            cout<<"Exceeds maximum length.\n";
        else
        {
            char *result = new char [MAX_LEN];
            result = strcpy(result, characterString);
            result = strcat(result, s.characterString);
            characterString = result;
        }
    }

    int operator ! () {return !(strlen(characterString));}

    char operator [] (int a) {return characterString[a];}

    friend ostream & operator << (ostream &out, const myString &s)
    {
        out<<s.characterString;
        return out;
    }

    myString() : characterString(""){}
};

char* operator + (char* s1, myString s2)
{
    if ((sizeof(s1)/sizeof(char)) + (sizeof(s2)/sizeof(char)) > MAX_LEN)
    {
        cout<<"Exceeds maximum length.\n";
        return "";
    }
    else
    {
        myString temp;
        temp = s1;
        return temp + s2;
    }
}

int main()
{
    myString s1;
    myString s2;
    if (!s1)    cout<<"Empty String"<<endl;
    else        cout<<s1<<endl;
    s1 = "Hello";
    s2 = "World";
    s1 = s1 + s2;
    cout<<s1<<endl;
    s1 = "Hello " + s2;
    cout<<s1<<endl;
    cout<<s2<<endl;
}
