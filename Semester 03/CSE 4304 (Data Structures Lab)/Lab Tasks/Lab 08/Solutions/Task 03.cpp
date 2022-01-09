#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> map;  // order not important; repeated keys
    int m, sum, temp, flag=0;

    cin>>m;
    if (m <= 0 || m >= 100) // values outside range
    {
        cout<<"Invalid input"<<endl;
        return 0;
    }

    for (int i=0; i<m; i++) // take input of array directly into map; O(n)
    {
        cin>>temp;
        map[temp]++;    // keep track of duplicates
    };
    cin>>sum;

    for (auto it = map.begin(); it != map.end(); it++) // O(n)
    {
        auto other = map.find(sum - it->first); // sum - arr[i]
        if (other != map.end() && other->second != 0)
            // if key is valid and has use left
        {
            if ((other->first == it->first && it->second > 1) || (other->first != it->first))
            // if the key found is equal to original key, it is only valid if it is a repeated key
            {
                if (!flag)  // only prints if nothing has been printed yet
                {
                    cout << "Pairs with sum " << sum << " are: ";
                    flag = 1;   // to indicate at least one value has been found
                }
				else
                    cout << ", "; // prints between pairs
                cout << "(" << it->first << ", " << other->first << ")";
            }
        }
        it->second--; // every pair possible with this value has been printed
    }
    // pairs formed by a key and another key which is a duplicate key are only printed once
    // printing more would take time complexity to O(n^2)

    if (!flag)  cout<<"No pairs found."<<endl;
    else        cout<<endl; // newline for valid print
}