#include<iostream>
#include<stack>
using namespace std;

void display(stack <int> s)     //function to display stack
{
    if (s.size() == 0)  cout<<"Size = 0 Items = NULL"<<endl;    //if stack is empty
    else
    {
        cout<<"Size = "<<s.size()<<" Items = ";
        int arr[s.size()], i=0;                 //create an array of same size as stack
        while (!s.empty())
        {
            arr[i] = s.top();   //store stack items in array in reverse order
            s.pop();            //to change top. actual stack unaffected size function given copy.
            i++;
        }

        for (int j=i-1; j>-1; j--) cout<<arr[j]<<" ";   //print array in reverse
        cout<<endl;
    }
}

int main()
{
    int n;  //stack size (built in stack does not need this)
    cin>>n;

    stack <int> s;

    int t, cmd; //number of commands
    cin>>t;

    for (int i=0; i<t; i++)
    {
        cin>>cmd;

        if (cmd == 1)   //if push
        {
            int num;
            cin>>num;

            if (s.size() < n)   s.push(num);
            display(s);
        }
        else if (cmd == 2)  //if pop
        {
            if (s.size() > 0)   s.pop();
            display(s);
        }

    }
}
