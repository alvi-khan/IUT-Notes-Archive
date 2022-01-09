#include<iostream>
#include<stack>
using namespace std;

int order(int arr[], int endArr)
{
    stack<int> road, side;
    road.push(0);           //will become obvious from rest

    for (int i=0; i<endArr; i++)
    {
        if (arr[i] == road.top()+1) road.push(arr[i]);  //add to main road if in order
        else
        {
            while (!side.empty() && side.top() == road.top()+1) //add from side road if following order
            {
                road.push(side.top());
                side.pop();
            }
            if (!side.empty() && side.top() < arr[i])   //theres stuff in side road thats smaller but too large for main road
            {
                cout<<"No"<<endl;
                return 0;
            }
            else
                side.push(arr[i]);  //side road stuff cant be added to main road but its not larger so okay
        }
    }
    cout<<"Yes"<<endl;
}

int main()
{
    int n;
    cin>>n;
    int arr[1005];
    while (n != 0)
    {
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        order(arr, n);
        cin>>n;                 //breaks everything if 0
    }
}
