#include<iostream>
using namespace std;

void linearEnqueue(int larr[], int input, int &lTail, int lQmax)
{
    if (lTail == lQmax)   cout<<"Queue full."<<endl;
    else
    {
        larr[lTail] = input;
        lTail++;
    }
}

void linearDequeue (int larr[], int &lHead, int lTail)
{
    if (lHead == lTail)   cout<<"Queue empty."<<endl;
    else
    {
        cout<<larr[lHead]<<" popped."<<endl;
        lHead++;
    }
}

void circularEnqueue(int carr[], int input, int &cTail, int &cCount, int cQmax)
{
    if (cCount == cQmax)    cout<<"Queue full."<<endl;
    else
    {
        carr[cTail] = input;
        cTail = (cTail+1)%cQmax;
        cCount++;
    }
}

void circularDequeue(int carr[], int &cHead, int &cCount, int cQmax)
{
    if (cCount == 0)    cout<<"Queue empty."<<endl;
    else
    {
        cout<<carr[cHead]<<" popped."<<endl;
        cHead = (cHead+1)%cQmax;
        cCount--;
    }
}

void displayLinearQueue(int larr[], int lHead, int lTail)
{
    cout<<"Linear Queue:"<<endl;
    for (int i=lHead; i<lTail; i++)
    {
        cout<<larr[i]<<" ";
    }
    cout<<endl;
}

void displayCircularQueue(int carr[], int cHead, int cTail, int cQmax, int cCount)
{
    cout<<"Circular Queue:"<<endl;

    if (cTail<=cHead && cCount != 0)    //if not empty and tail is reved
    {
        for (int i=0; i<cTail; i++)
        {
            cout<<carr[i]<<" ";
        }
        for (int i=cTail; i<cHead; i++)
        {
            cout<<"- ";
        }
        for (int i=cHead; i<cQmax; i++)
        {
            cout<<carr[i]<<" ";
        }
    }
    else if (cTail>cHead)               //else print from head to tail
    {
        for (int i=cHead; i<cTail; i++)
        {
            cout<<carr[i]<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int larr[5], lTail = 0, lHead = 0, lQmax = 5;
    int carr[5], cTail = 0, cHead = 0, cQmax = 5, cCount = 0;

    int n = -1;

    while (n != 5)
    {
        cout<<endl<<"What would you like to do?"<<endl<<"1. Push into linear queue.\n2. Pop from linear queue.\n3. Push into circular queue.\n4. Pop from circular queue.\n5. Exit."<<endl;
        cin>>n;

        if (n == 1)
        {
            int input;
            cout<<"Enter item to insert: ";
            cin>>input;
            linearEnqueue(larr, input, lTail, lQmax);
        }
        else if (n == 2)
        {
            linearDequeue(larr, lHead, lTail);
        }
        else if (n == 3)
        {
            int input;
            cout<<"Enter item to insert: ";
            cin>>input;
            circularEnqueue(carr, input, cTail, cCount, cQmax);
        }
        else if (n == 4)
        {
            circularDequeue(carr, cHead, cCount, cQmax);
        }
        else if (n == 5)    exit(1);

        if (n == 1 || n == 2)   displayLinearQueue(larr, lHead, lTail);
        else if (n==3 || n==4)  displayCircularQueue(carr, cHead, cTail, cQmax, cCount);
    }
}
