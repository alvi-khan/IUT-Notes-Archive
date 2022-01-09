#include <bits/stdc++.h>
using namespace std;

int arr[1000];	// array to store values

int binarySearch(int lowerBound, int upperBound, int target)
{
    int midPoint;	// index of mid-point of range
    while(lowerBound <= upperBound)	// while range is getting smaller
    {
        midPoint = (lowerBound + upperBound) / 2;					// find mid-point
        if(arr[midPoint] == target)		return mid;					// if target found, return index
        else if(arr[midPoint] > target)	upperBound = midPoint - 1;	// if mid-point value is too large, decrease upper bound
        else							lowerBound = midPoint + 1;	// if mid-point value is too small, increase lower bound
    }
    return -1;	// return if target not found
}

int main()
{
    
}