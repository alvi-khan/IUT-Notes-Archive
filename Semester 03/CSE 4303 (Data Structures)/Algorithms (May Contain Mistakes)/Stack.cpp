#include<iostream>
using namespace std;

void push (int S[], int maxLen, int item, int &top)
{
    if (top != maxLen)
    {
        S[top] = item;
        top++;
    }
}

void pop (int S[], int &top)
{
    if (top != 0)
    {
        top--;
        cout<<S[top];
    }
}

bool isEmpty (int top)
{
    if (top == 0)   return true;
    else            return false;
}

bool isFull (int top, int maxLen)
{
    if (top == maxLen)  return true;
    else                return false;
}

void clearStack (int &top)
{
    top = 0;
}

int getTop (int Q[], int top)
{
    return Q[top];
}

int getSize (int top)
{
    return top;
}

int main()
{

}
