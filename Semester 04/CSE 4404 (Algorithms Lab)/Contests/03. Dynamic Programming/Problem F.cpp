#include<bits/stdc++.h>
using namespace std;

#define modulo 998244353

long long numbers[120];         // store the number of problems in each difficulty level
long long memo[120][120];       // store number of possible problems from i if k levels are left

long long f(int i, int k)
{
    if (memo[i][k] != -1)   return memo[i][k];  // memoized value
    if (numbers[i] == 0)    return 0;           // 0 problems with this difficulty level
    if (k == 1)             return numbers[i];  // just one problem left, so return this value
    long long total = 0;
    for (int j=i-1; j>0; j--)   total = (total + f(j, k-1))%modulo; // take this level and start from each of the levels below it
    return memo[i][k] = (total * numbers[i])%modulo;                    // all possibilities * number of problems in self
}

int main()
{
    int n, k, num, maxVal = -1;
    memset(numbers, 0, sizeof(numbers));
    memset(memo, -1, sizeof(memo));
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>num;
        if (num > maxVal)   maxVal = num;   // keep track of the maximum value since we need to loop
        numbers[num]++;                     // increment number of problems of this level
    }
    long long total = 0;
    for (int i=maxVal; i>0; i--)    total = (total + f(i, k))%modulo;   // total possibilities starting at each level
    cout<<total<<endl;
}