#include <bits/stdc++.h>
using namespace std;

bool memo[110];

bool f(int target)
{
    if (memo[target] || !(target))  return true;    // memoized value is true or target is 0
    if (target < 0)                 return false;   // went too far
    return memo[target] = (f(target-3) || f(target-7)); // at each point try to take away either 3 or 7
}

int main()
{
    int n;
    cin>>n;
    memset(memo, false, sizeof(memo));
    while(n--)
    {
        int x;
        cin>>x;
        if (f(x))   cout<<"YES"<<endl;
        else        cout<<"NO"<<endl;
    }
}