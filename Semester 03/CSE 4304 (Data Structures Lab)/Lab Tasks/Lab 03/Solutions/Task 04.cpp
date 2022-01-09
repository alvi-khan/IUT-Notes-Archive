#include<iostream>
#include<string>

using namespace std;

int main()
{
    int dataSets;

    cin>>dataSets;

    for (int i=0; i<dataSets; i++)
    {
        int strLen, strNum;

        cin>>strLen>>strNum;

        string data[strNum];
        int inversions[strNum];

        for (int j=0; j<strNum; j++)
        {
            cin>>data[j];

            int c=0, g=0, t=0, curInv=0;        //storing number of each character

            for (int k=0; k<strLen; k++)
            {
                if (data[j].at(k) == 'T')      t++;
                else if (data[j].at(k) == 'G')  //add number of greater character in curInv
                {
                    g++;
                    curInv += t;
                }
                else if (data[j].at(k) == 'C')
                {
                    c++;
                    curInv += (t+g);
                }
                else if (data[j].at(k) == 'A') curInv += (t+g+c);
            }
            inversions[j] = curInv;         //store curInv at index of same string
        }

        for (int j=0; j<strNum; j++)
        {
            for (int k=0; k<j; k++)         //sort both arrays together
            {
                if (inversions[j] < inversions[k])
                {
                    int tempInt = inversions[j];
                    string tempStr = data[j];
                    inversions[j] = inversions[k];
                    data[j] = data[k];
                    inversions[k] = tempInt;
                    data[k] = tempStr;
                }
            }
        }

        cout<<endl;

        for (int j=0; j<strNum; j++)    cout<<data[j]<<" "<<inversions[j]<<endl;

        cout<<endl;
    }
}
