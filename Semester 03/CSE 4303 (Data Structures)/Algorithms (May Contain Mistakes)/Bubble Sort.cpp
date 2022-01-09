#include<iostream>
using namespace std;

void bubbleSort (int A[], int length)
{
    for (int i=0; i<length; i++)
    {
        for (int j=length; j>i+1; j--)
        {
            if (A[j] < A[j-1])
            {
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
    }
}

int main()
{

}
