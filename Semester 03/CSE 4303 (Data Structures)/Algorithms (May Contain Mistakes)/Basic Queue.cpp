#include<iostream>
using namespace std;

void enqueue (int Q[], int addition, int &tail, int qMax)
{
    if (tail != qMax)
    {
        Q[tail] = addition;
        tail++;
    }
}

void dequeue (int Q[], int &head, int tail)
{
    if (head != tail)
    {
        cout<<Q[head]<<endl;
        head++;
    }
}

bool isEmpty (int head, int tail)
{
    if (head == tail)   return true;
    else                return false;
}

int getHead (int Q[], int head, int tail)
{
    if (head != tail)   return Q[head];
    else                return NULL;
}

bool isFull (int tail, int qMax)
{
    if (tail == qMax)   return true;
    else                return false;
}

int queueSize (int head, int tail)
{
    return tail - head;
}

int main()
{

}
