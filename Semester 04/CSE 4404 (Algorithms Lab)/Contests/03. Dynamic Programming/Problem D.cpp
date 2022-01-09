#include<bits/stdc++.h>
using namespace std;

long long numbers[100050];      // store (frequency * digit) for each possible digit
long long memo[100050];         // memoize maximum value for each possible digit

long long f(long long i)
{
    if (i == 1)             return numbers[i];  // last position reached
    if (i == 0)             return 0;           // nothing left
    if (numbers[i] == 0)    return f(i-1);   // this number does not exist, keep going
    if(memo[i] != -1)       return memo[i];     // memoized number
    return memo[i] = max(f(i-1), f(i-2)+numbers[i]);    // find maximum of taking this digit or not taking it
}

int main()
{
    long long n, num, maxVal = -1;
    memset(numbers, 0, sizeof(numbers));
    memset(memo, -1, sizeof(memo));
    cin>>n;
    for (long long i=1; i<=n; i++)
    {
        cin>>num;
        if (num > maxVal)   maxVal = num;   // keep track of maximum value
        numbers[num] += num;                // total value at each level
    }
    cout<<f(maxVal)<<endl;
}