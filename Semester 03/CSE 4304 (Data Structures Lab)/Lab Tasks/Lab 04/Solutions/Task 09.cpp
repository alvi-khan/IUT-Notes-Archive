#include<iostream>
#include<stack>
using namespace std;

void braceCount(string input)
{
    stack <char> closingBraces, openingBraces;

    for (int i=input.length()-1; i>-1; i--) //going backwards
    {
        char a = input.at(i);
        if (a == '(' && !closingBraces.empty()) //if there is a closing brace, pop
            closingBraces.pop();()
        else if (a == '(')                      //no closing braces, push to openingBrace stack
            openingBraces.push(a);
        else if (a == ')')                      //push closing braces into stack
            closingBraces.push(a);
    }

    cout<<closingBraces.size()+openingBraces.size();    //result is total number of lonely braces
}

int main()
{
    string input;
    cin>>input;
    braceCount(input);
}
