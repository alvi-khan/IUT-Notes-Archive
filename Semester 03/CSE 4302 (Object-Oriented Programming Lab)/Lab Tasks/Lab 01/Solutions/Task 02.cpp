#include<iostream>

using namespace std;

float ctof(float c)
{
    float f=(c*9/5)+32;
    return f;
}

float ftoc(float f)
{
    float c=(f-32)*5/9;
    return c;
}

int main()
{
    int n, i;
    cout<<"Enter number of terms: ";    //number of terms in series
    cin>>n;
    float nums[n];

    if (n>0)    nums[0] = 1;
    if (n>1)    nums[1] = 2;

    if (n>2)    for (i=2; i<n; i++) nums[i] = nums[i-1] + nums[i-2];    //create series

    if (n == 0) cout<<"No data";
    else
    {
        cout<<"\n\tCelsius\tFahrenheit\n\n";

        for (i=0; i<n; i++) cout<<nums[i]<<"\t"<<ctof(nums[i])<<"\t"<<ftoc(nums[i])<<endl;
    }
}
