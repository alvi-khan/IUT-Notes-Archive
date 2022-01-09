#include<bits/stdc++.h>
#include<string>
using namespace std;

string arr[1000];
int n;

void countSort(int pos)
{
    string res[n];
    int counter[256] = {0};     // will keep count of number of each character

    for(int j=0; j<n; j++)      // count number of each character
    {
        int index = arr[j][pos];
        counter[index]++;
    }

    for(int j=1; j<256; j++)    counter[j] += counter[j-1]; // cumulative sum

    for (int j=n-1; j>-1; j--)  // set new indices; loop must come from backwards, order gets messed up otherwise (try it)
    {
        int oldIndex = arr[j][pos];
        int newIndex = counter[oldIndex] - 1;
        res[newIndex] = arr[j];
        counter[oldIndex]--;
    }

    for (int j=0; j<n; j++)     arr[j] = res[j];    // copy results
}


void radixSort()
{
    for (int i=10 - 1; i>-1; i--)  countSort(i);    // loop over every position
}

int main()
{
    
}