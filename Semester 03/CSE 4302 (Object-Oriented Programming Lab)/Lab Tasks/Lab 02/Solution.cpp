#include<iostream>
#include<sstream>

using namespace std;

struct card
{
    int suit;
    int num;
};

card arr[4];        //array of cards

string getSuit(int suit)
{
    if (suit == 1)  return "Spades";
    else if (suit == 2) return "Hearts";
    else if (suit == 3) return "Clubs";
    else if (suit == 4) return "Diamonds";
}

string getNum(int num)
{
    if (num > 9)
        {
            if      (num == 10)  return "Jack";
            else if (num == 11)  return "Queen";
            else if (num == 12)  return "King";
            else if (num == 13)  return "Ace";
        }
    else
    {
        stringstream ss;        //convert num to string
        ss<<num;
        return ss.str();
    }
}

int main()
{

    int i;

    for (i=0; i<4; i++)
    {
        cout<< "Suit: ";
        cin >> arr[i].suit;
        cout<< "No.: ";
        cin >> arr[i].num;
    }

    for (i=0; i<4; i++)
    {
        cout<<"Card "<<i+1<<" is "<<getNum(arr[i].num)<<" of "<<getSuit(arr[i].suit)<<endl;
    }

}
