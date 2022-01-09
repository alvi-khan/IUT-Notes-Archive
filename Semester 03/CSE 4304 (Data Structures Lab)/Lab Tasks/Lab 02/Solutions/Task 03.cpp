#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int T;

    cin>>T;

    for (int i=0; i<T; i++)
    {
        double N, A, B;

        cin>>N>>A>>B;

        double xD;

        int cost, x, y;     //mathematics

        xD = ((B*N)/(A+B));
        x = round(xD);
        y=N-x;
        cost = (A*x*x)+(B*y*y);

        cout<<cost<<" "<<x<<" "<<y<<endl;
    }
}
