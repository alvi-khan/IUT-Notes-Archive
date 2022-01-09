#include <iostream>
#include <string>
using namespace std;

int checkStr(string pattern, string text, int start, int len)   // checks if the strings match
{
    for (int i=0; i<len; i++)   // O(n)
        if (text[start+i] != pattern[i])    return 0;   // mismatch found
    cout<<"Pattern found at index: "<<start<<endl;
    return 1;    // if pattern found returns 1
}

int main()
{
    string text, pattern;
    getline(cin, text);
    getline(cin,pattern);

    int flag=0, textLen = text.length(), patternLen = pattern.length(), patternVal=0, windowVal=0;

    for (int i=0; i<patternLen; i++)
    {
        patternVal += int(pattern[i]) * 7;  // this would be the hash function
        windowVal += int(text[i]) * 7;
    }

    if (windowVal == patternVal)    // initial check
    {
        if(checkStr(pattern, text, 0, patternLen)) // if pattern found
            flag = 1;   // so last line not printed
    }

    for (int i=patternLen; i<textLen; i++)  // O(n)
    {
        windowVal -= (int(text[i-patternLen]) * 7); // rolling hash
        windowVal += (int(text[i]) * 7);
        if (windowVal == patternVal)
        {
            if(checkStr(pattern, text, i-patternLen+1, patternLen)) // O(mn) in worst case; O(m+n) if I'm a good programmer
                flag = 1;
        }
    }
    // I'm sure the initial checkStr can be combined with the loop by changing where the loop starts and ends
    // but it's midnight and I'm tired
    if (!flag)  cout<<"Pattern not found!"<<endl;
}