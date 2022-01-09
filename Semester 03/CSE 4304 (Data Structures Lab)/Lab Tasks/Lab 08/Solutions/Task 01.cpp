#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> first;  // order not important
    int m, n, temp, flag=0;

    cin>>m>>n;
    if (m <= 0 || m >= 100 || n <= 0 || n >= m) // values outside range
    {
        cout<<"Invalid input"<<endl;
        return 0;
    }

    for (int i=0; i<m; i++) // take input of first array directly into map; O(n)
    {
        cin>>temp;
        first.insert({temp, 1});
    };

    for (int i=0; i<n; i++) // O(n)
    {
        cin>>temp;
        if (first.find(temp) == first.end())    flag = 1;   // if not in map
    }

    if (flag == 1)  cout<<"b_array is a not subset of a_array"<<endl;   // at least one member was missing
    else            cout<<"b_array is a subset of a_array"<<endl;
}