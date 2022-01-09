#include<bits/stdc++.h>
using namespace std;

int notes[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long memo[15][30100];  // memoize number of ways target can be reached from ith coin

long long f(int note, int target)
{
    if (memo[note][target] != -1)   return memo[note][target];  // memoized values
    if (target == 0)                return 1;                   // target reached
    else if (note == 11)            return 0;                   // no more coins
    int repeats = 0;
    long long possibilities = 0;
    while (true)                                                // keep increasing number of ith coin until too large
    {
        int total = repeats * notes[note];
        if (total > target) break;
        possibilities += f(note+1, target-total);
        repeats++;
    }
    return memo[note][target] = possibilities;
}

int main()
{
    float total = 1000.00;
    memset(memo, -1, sizeof(memo));
    while (cin>>total)
    {
        if (total == 0.00) break;
        long long possibilities = f(0, round(total*100));   // floats cause inaccuracies
        cout<<right<<setw(6)<<fixed<<setprecision(2)<<total<<right<<setw(17)<<possibilities<<endl;
    }
}