/*
    In postfix notation, we store each number in a stack.
    When we find an operator, we pop two items.
    The first item goes to the right of the operator.
    The second item goes to the left of the operator.
    The result is stored in the stack.

    345*+6-

    Stack 3->4->5
    Stack 3->(4*5=20)
    Stack (3+20=23)
    Stack 23->6
    Stack (23-6=17)
*/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int t;  //number of inputs
    cin>>t;

    for (int i=0; i<t; i++)
    {
        stack <int> s;
        string input;   //current input
        cin>>input;

        for (int j=0; j<input.length(); j++)
        {
            int cur = input.at(j);  //current character
            if (cur < 58 && cur > 47)   s.push(cur - 48);   //if number, store number (-48 becuz ASCII)
            else                    // if operator
            {
                int right = s.top();    //top goes to right side of operator
                s.pop();
                int left = s.top();     //next top goes to left side of operator
                s.pop();

                //check which operator and push result

                if (cur == 43)  s.push(left+right);
                else if (cur == 45) s.push(left-right);
                else if (cur == 42) s.push(left*right);
                else if (cur == 47) s.push(left/right);
            }
        }
        cout<<s.top()<<endl;    //display final result
    }
}
