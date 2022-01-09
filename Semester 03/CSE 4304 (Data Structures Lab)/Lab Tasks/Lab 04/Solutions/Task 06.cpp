#include<iostream>
#include<stack>
using namespace std;

/*
    For any element, if there are elements after it in the stack that are smaller,
    any elements that come before it cannot have those elements as results. So,
    the smaller elements can be popped.
*/

void NGE(int arr[], int j)
{
    stack<int> a;
    int results[100], k=1;
    results[0] = -1;        //first member is -1

    a.push(arr[j]);         //push last array element to stack

    for (int i=j-1; i>-1; i--)
    {
        while (a.top()<=arr[i])     //while top is not greater, pop elements
        {
            a.pop();
            if (a.empty())  break;
        }
        if (a.empty())              //if it becomes empty, add -1 to results
        {
            results[k] = -1;
        }
        else                        //if larger element is found, add it to result
        {
            results[k] = a.top();
        }
        a.push(arr[i]);             //push current element to stack
        k++;
    }

    for (int i=k-1; i>-1; i--)  cout<<results[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        int arr[100], j=0;
        int input;

        while (cin>>input)              //add inputs to array until -1
        {
            if (input == -1)    break;
            else
            {
                (arr[j] = input);
                j++;
            }
        }
        j--;
        NGE(arr, j);
    }
}
