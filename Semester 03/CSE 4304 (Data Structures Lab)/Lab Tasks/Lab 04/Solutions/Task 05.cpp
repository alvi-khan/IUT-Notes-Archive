#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int t;  //number of inputs
    cin>>t;

    for (int j=0; j<t; j++)
    {
        int flag = 0;   //track validity
        stack <int> s;
        string input;  //store input. WARNING. PDF inputs have spaces. Spaces cause problems since its a string.
        cin>>input;

        for (int i=0; i<input.length(); i++)
        {
            int cur = input.at(i);  //current character

            if ((cur == 40) || (cur == 123) || (cur == 91)) s.push(cur);    //if cur is opening brace, push
            else if ((cur == 41 && (s.top() == 40)) || (cur == 125 && (s.top() == 123)) || (cur == 93 && (s.top() == 91)))
                s.pop();
                //if cur is closing brace and matches stack top, pop
            else if ((cur == 41 && (s.top() != 40)) || (cur == 125 && (s.top() != 123)) || (cur == 93 && (s.top() != 91)))
            {
                flag = 1;   //invalid if cur is closing brace but does not match stack top
                break;      //no need to check rest of input, already invalid
            }
        }

        if (!s.empty()) flag = 1;   //if end of input reached and opening braces still is stack (no closing brace), invalid

        if (flag == 0)  cout<<"Yes"<<endl;
        else if (flag == 1) cout<<"No"<<endl;
    }
}
