#include<iostream>
using namespace std;

void enqueue (int Q[], int x, int &tail, int qMax, int &total)
{
    if (total != qMax)
    {
        Q[tail] = x;
        tail = (tail +1)%qMax;
        total++;
    }
}

void dequeue (int Q[], int qMax, int &head, int &total)
{
    if (total != 0)
    {
        cout<<Q[head];
        head = (head+1)%qMax;
        total--;
    }
}

bool isEmpty (int total)
{
    if (total == 0) return true;
    else            return false;
}

int getHead (int Q[], int head)
{
    return Q[head];
}

bool isFull (int total, int qMax)
{
    if (total == qMax)  return true;
    else                return false;
}

int getSize (int total)
{
    return total;
}

int main()
{

}
