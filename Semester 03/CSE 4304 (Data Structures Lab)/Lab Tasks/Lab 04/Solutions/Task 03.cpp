#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <char> s;
    int n;          //number of inputs
    cin>>n;

    for (int i=0; i<n; i++)
    {
        string input;   //get input
        cin>>input;

        for (int j=0; j<input.length(); j++)
        {
            s.push(input.at(j));    //push each character to stack
        }

        while (!s.empty())
        {
            cout<<s.top();          //display top item and pop stack
            s.pop();
        }
        cout<<endl;
    }
}
