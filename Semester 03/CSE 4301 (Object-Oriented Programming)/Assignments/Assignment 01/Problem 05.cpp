#include<iostream>
using namespace std;

class Player
{
    string name;
    int runs;

public:
    void setName(string a) {name = a;}
    string getName() {return name;}

    void addRuns(int a) {runs += a;}
    int getRuns() {return runs;}

    Player() : runs(0) {}
};

class Team
{
    string highestScorer;
    string teamName;
public:
    Player a[11];

    void setTeamName(string a) {teamName = a;}
    string getTeamName() {return teamName;}

    int getHighestScore()
    {
        int highestScore = 0;
        for (int i=0; i<11; i++)
        {
            if (a[i].getRuns() > highestScore)
            {
                highestScore = a[i].getRuns();
                highestScorer = a[i].getName();
            }
        }
        return highestScore;
    }
    string getHighestScorer() {return highestScorer;}

    int getTotal()
    {
        int totalRuns = 0;
        for (int i=0; i<11; i++)    totalRuns += a[i].getRuns();
        return totalRuns;
    }

    Team() : highestScorer(""), teamName("") {}
};

class Match
{
    string winner;
public:
    Team b[2];
    string getManOfMatch()
    {
        if (b[0].getHighestScore() > b[1].getHighestScore())    return b[0].getHighestScorer();
        else    return b[1].getHighestScorer();
    }

    string getWinner()
    {
        if (b[0].getTotal() > b[1].getTotal())  winner = b[0].getTeamName();
        else                                    winner = b[1].getTeamName();
        return winner;
    }
};

int main()
{
    Match m1;

    for (int i=0; i<11; i++)
    {
        m1.b[0].a[i].addRuns(1);
    }

    m1.b[0].a[0].addRuns(1);

    for (int i=0; i<11; i++)
    {
        m1.b[1].a[i].addRuns(2);
    }
    m1.b[1].a[0].addRuns(2);

    m1.b[0].a[0].setName("A");
    m1.b[1].a[0].setName("B");

    m1.b[1].setTeamName("Team B");

    cout<<m1.getWinner()<<endl;
    cout<<m1.getManOfMatch();
}
