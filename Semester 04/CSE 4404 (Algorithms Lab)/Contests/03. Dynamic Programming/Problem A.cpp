#include <bits/stdc++.h>
using namespace std;
string str1, str2;
int memo[1005][1005];   // store memoized values

int f(int i, int j)
{
    if (i == -1 || j == -1)     return 0;           // string length exceeded
    else if (memo[i][j] != -1)  return memo[i][j];  // memoized value exists

    if (str1[i] == str2[j])     memo[i][j] = f(i-1, j-1) + 1;   // characters match -> add 1 to results
    else                        memo[i][j] = max(f(i-1, j), f(i, j-1)); // charcters don't match -> try both possibilities
    return memo[i][j];
}

int main()
{
    while (getline(cin, str1) && getline(cin, str2))    // getline needed to not ignore blank lines
    {
        memset(memo, -1, sizeof(memo));
        cout<<f(str1.length()-1, str2.length()-1)<<endl;
    }
}