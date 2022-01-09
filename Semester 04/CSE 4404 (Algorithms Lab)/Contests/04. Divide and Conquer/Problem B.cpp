#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main()
{
    int N = -1, in, num1, num2;
    while (true)
    {
        cin>>N;
        if (N == 0) break;
        for (int i=0; i<N; i++)
        {
            cin>>in;
            q.push(in);
        }
        int res = 0;
        while (q.size() != 1)       // always add smallest two values; add sum to result; add sum back to queue
        {
            num1 = q.top();
            q.pop();
            num2 = q.top();
            q.pop();
            q.push(num1 + num2);    // push result back to queue; check example - adding 4 numbers needs 3 additions
            res += num1 + num2;
        }
        cout<<res<<endl;
        q.pop();
    }
}

// e.g. 3 4 5 6 -> 3 + 4 = 7; 5 + 6 = 11; 7 + 11 = 18; result = 7 + 11 + 18 = 36