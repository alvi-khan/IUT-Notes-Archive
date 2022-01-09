#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[25];

bool sortCmd(const pair<int,int> &a, const pair<int,int> &b)    // parameter for sorting pairs
{
    if (a.second == b.second)   return (a.first < b.first);     // sort by second element, then first
    else                        return (a.second < b.second);
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int input = 0, first, second;
        while (true)
        {
            cin>>first>>second;
            if (first == 0 && second == 0)  break;
            arr[input] = {first, second};
            input++;
        }

        sort(arr, arr + input, sortCmd);            // sort ascending based on second element

        int limit = arr[0].second, count = 1;           // first member
        for (int j=1; j<input; j++)
        {
            if (arr[j].first < limit)  continue;        // invalid member
            else
            {
                limit = arr[j].second;                  // valid member
                count++;
            }
        }
        cout<<count<<endl;
    }
}