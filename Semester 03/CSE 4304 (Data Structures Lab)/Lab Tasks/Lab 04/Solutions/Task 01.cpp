#include<iostream>
using namespace std;

void display(int arr[], int tail)   //function to display stack
{
    if (tail == 0)  cout<<"Size = 0 Items = NULL"<<endl;    //if stack is empty
    else
    {
        cout<<"Size = "<<tail<<" Items = ";
        for (int i=0; i<tail; i++)  cout<<arr[i]<<" ";
        cout<<endl;
    }
}

void push(int num, int n, int arr[], int &tail)
{
    if (tail != n)  //if stack is not full
    {
        arr[tail] = num;    //add num to current tail position and increment tail
        tail++;
    }
}

void pop(int &tail)
{
    if (tail != 0)  tail--;
}

int main()
{
    int n;  //size of stack
    cin>>n;
    int arr[n];

    int t, cmd, tail=0; //number of commands and first tail position
    cin>>t;

    for (int i=0; i<t; i++)
    {
        cin>>cmd;

        if (cmd == 1)   //if push
        {
            int num;
            cin>>num;
            push (num, n, arr, tail);   //push num
            display(arr, tail);         //display stack
        }
        else if (cmd == 2)  //if pop
        {
            pop(tail);                  //pop num
            display(arr, tail);         //display stack
        }
    }
}
