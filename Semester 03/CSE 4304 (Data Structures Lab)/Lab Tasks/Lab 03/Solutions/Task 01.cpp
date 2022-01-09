#include<iostream>
#include<stdio.h>

using namespace std;

float nums[100];
int indexes[100];

int main()
{
    int tests;
    cin>>tests;

    for (int i=0; i<tests; i++)
    {
        int input = 0;
        int j = 0;

        while (input != -1)         //first array is indexes of second array
        {
            cin>>input;
            indexes[j] = input;
            j++;
        }

        for (int k=0; k<j-1; k++)   //store second array in the indexes given by first array
        {
            int index = indexes[k];
            cin>>nums[index];
        }

        for (int k=1; k<j; k++) printf("%0.2f\n", nums[k]);
    }
}
