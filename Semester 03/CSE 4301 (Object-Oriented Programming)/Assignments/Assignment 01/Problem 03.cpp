#include<iostream>
using namespace std;

class Candidate
{
    static int totalCands;
    static int aggregateScores[4000];
    const int examID;
    int pNum;
    int examOne;
    int examTwo;

public:
    void addToMeritList();
    int getMerit();
    void setExamOne(int a) {examOne = a;}
    int getExamOne() {return examOne;}
    void setExamTwo(int a) {examTwo = a;}
    int getExamTwo() {return examTwo;}
    void setPnum(int a) {pNum = a;}
    int getPnum() {return pNum;}
    int getExamID() {return examID;}
    int getTotalCands() {return totalCands;}
    int getMaxMark() {return aggregateScores[0];}
    Candidate() : examID(totalCands+1), pNum(0), examOne(0), examTwo(0) {totalCands++;}
};

int Candidate :: totalCands = 0;
int Candidate :: aggregateScores[4000] = {0};

void Candidate :: addToMeritList()
{
    int i = 0, score = (examOne*10 + examTwo*10);
    for (i=totalCands-2; i>-1; i--)
    {
        if (aggregateScores[i] < score) {aggregateScores[i+1] = aggregateScores[i];}
        else    break;
    }
    aggregateScores[i+1] = score;
}

int Candidate :: getMerit()
{
    int score = (examOne*10 + examTwo*10);
    for (int i=0; i<totalCands; i++)    if (score == aggregateScores[i])    return i+1;
    return -1;
}



int main()
{
    Candidate c1;
    c1.setExamOne(10);
    c1.setExamTwo(10);
    c1.addToMeritList();

    cout<<c1.getMerit()<<endl;


    Candidate c2;
    c2.setExamOne(20);
    c2.setExamTwo(20);
    c2.addToMeritList();


    cout<<c2.getMerit()<<endl;
    cout<<c1.getMaxMark()<<endl;
    cout<<c2.getExamID()<<endl;

}
