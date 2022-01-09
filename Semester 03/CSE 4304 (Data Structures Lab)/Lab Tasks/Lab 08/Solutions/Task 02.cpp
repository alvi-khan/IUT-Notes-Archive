#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n, temp;
    unordered_map<int, int> map;  // order not important

    cin>>n;
    if (n >= 100 || n <= 0) // values outside range
    {
        cout<<"Invalid input"<<endl;
        return 0;
    }

    for (int i=0; i<n; i++) // take input of array directly into map; O(n)
    {
        cin>>temp;
        map[temp]++;
    }

    int max = -1, maxKey = -1;   // assuming all values are positive
    for (auto it = map.begin(); it != map.end(); it++) // find max value in map; O(n)
    {
        if (it->second > max)
        {
            max = it->second;
            maxKey = it->first;
        }
    }

    cout<<"Most frequent element: "<<maxKey<<endl<<"Frequency: "<<max<<endl;


}