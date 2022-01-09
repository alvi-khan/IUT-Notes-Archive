#include<iostream>
#include<stack>
using namespace std;

void postFix(string input)
{
    stack<char> results, operators;

    for (int i=0; i<input.length(); i++)
    {
        char a = input.at(i);

        if (a<123 && a>96)  results.push(a);    //if alphabet push to result
        else if (a == '(')   operators.push(a); //if opening brace push to operators
        else if (a == ')')                      //if closing brace push everything to result until opening brace
        {
            while (operators.top() != '(')
            {
                results.push(operators.top());
                operators.pop();
            }
            operators.pop();
        }
        else if (a == '*')                      //if * push larger operators to result then push * to operators
        {
            while (!operators.empty() && (operators.top() == '/' || operators.top() == '^'))
            {
                results.push(operators.top());
                operators.pop();
            }
            operators.push(a);
        }
        else if (a == '+' || a == '-')  //similar to * but every operator has larger ascii value except *
        {
            while (!operators.empty() && (operators.top()>a || operators.top() == '*'))
            {
                results.push(operators.top());
                operators.pop();
            }
            operators.push(a);
        }
        else    //similar but made for / and ^
        {
            while (!operators.empty() && (operators.top() > a))
            {
                results.push(operators.top());
                operators.pop();
            }
            operators.push(a);
        }
    }

    while (!operators.empty())  //for operators outside of any braces
    {
        results.push(operators.top());
        operators.pop();
    }

    char arr[400];
    int i=0;

    while (!results.empty())                     //store stack in array
    {
        arr[i] = results.top();
        results.pop();
        i++;
    }

    for (int j=i-1; j>-1; j--) cout<<arr[j];    //print array in reverse
    cout<<endl;
}

int main()
{
    int t;

    cin>>t;

    for (int i=0; i<t; i++)
    {
        string input;
        cin>>input;
        postFix(input);
    }
}
