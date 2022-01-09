#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int nums[100];

int main()
{
    string input;
    int numNum = 0;

    cin>>input;

    for (int i=0; i<input.length(); i+=2)       //convert number chars to ints
    {
        nums[numNum] = input.at(i)-48;
        numNum++;
    }


    sort (nums, nums+numNum);                   //sort ints and print

    for (int j=0; j<numNum-1; j++)   cout<<nums[j]<<"+";
    cout<<nums[numNum-1];
}
