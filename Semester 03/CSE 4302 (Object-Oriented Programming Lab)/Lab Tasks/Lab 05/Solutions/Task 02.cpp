// cardaray.cpp
// cards as objects
#include <iostream>
#include <cstdlib> //for srand(), rand()
#include <ctime> //for time for srand()
#include <iomanip>
using namespace std;
enum Suit { clubs, diamonds, hearts, spades };
//from 2 to 10 are integers without names
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
////////////////////////////////////////////////////////////////
class card
{
private:
    int number; //2 to 10, jack, queen, king, ace
    Suit suit; //clubs, diamonds, hearts, spades
public:
    card() //constructor
    { }
    void set(int n, Suit s) //set card
    {
        suit = s;
        number = n;
    }
    void display(); //display card

    Suit getSuit(){return suit;}
    int getNumber(){return number;}
};
//--------------------------------------------------------------
void card::display() //display the card
{
    if( number >= 2 && number <= 10 )
        cout << setw(2) << setfill(' ')<< number;
    else
        switch(number)
        {
        case jack:
            cout << " J";
            break;
        case queen:
            cout << " Q";
            break;
        case king:
            cout << " K";
            break;
        case ace:
            cout << " A";
            break;
        }
    switch(suit)
    {
    case clubs:
        cout << "C";
        break;
    case diamonds:
        cout << "D";
        break;
    case hearts:
        cout << "H";
        break;
    case spades:
        cout << "S";
        break;
    }
}

void displaySortedHand(card deck[], int firstCard)
{

    card tempDeck[13];
    int j = firstCard;
    for (int i=0; i<13; i++)    //add every four cards to tempDeck
    {
        tempDeck[i] = deck[j];
        j+=4;
    }

    for (int i=0; i<13; i++)    //sort tempDeck first by suit, and then by number
    {
        for (int j=0; j<i; j++)
        {
            if (tempDeck[j].getSuit()>tempDeck[i].getSuit())    //sort suits
            {
                card temp = tempDeck[j];
                tempDeck[j] = tempDeck[i];
                tempDeck[i] = temp;
            }
            //then sort numbers
            else if (tempDeck[j].getSuit() == tempDeck[i].getSuit() && tempDeck[j].getNumber()>tempDeck[i].getNumber())
            {
                card temp = tempDeck[j];
                tempDeck[j] = tempDeck[i];
                tempDeck[i] = temp;
            }
        }
    }

    for (int i=0; i<13; i++)    //display tempDeck
    {
        tempDeck[i].display();
        cout<<", ";
    }
    cout<<endl;
}

int main()
{
    card deck[52];
    int j;
    cout << endl;
    for(j=0; j<52; j++) //make an ordered deck
    {
        int num = (j % 13) + 2; //cycles through 2 to 14, 4 times
        Suit su = Suit(j / 13); //cycles through 0 to 3, 13 times
        deck[j].set(num, su); //set card
    }
    cout << "\nOrdered deck:\n";
    for(j=0; j<52; j++) //display ordered deck
    {
        deck[j].display();
        cout << " ";
        if( !( (j+1) % 13) ) //newline every 13 cards
            cout << endl;
    }
    srand( time(NULL) ); //seed random numbers with time
    for(j=0; j<52; j++) //for each card in the deck,
    {
        int k = rand() % 52; //pick another card at random
        card temp = deck[j]; //and swap them
        deck[j] = deck[k];
        deck[k] = temp;
    }
    cout << "\nShuffled deck:\n";
    for(j=0; j<52; j++) //display shuffled deck
    {
        deck[j].display();
        cout << ", ";
        if( !( (j+1) % 13) ) //newline every 13 cards
            cout << endl;
    }

    cout << "\nSerial Hands:\n";

    displaySortedHand(deck, 0); //first hand
    displaySortedHand(deck, 1); //second hand
    displaySortedHand(deck, 2); //third hand
    displaySortedHand(deck, 3); //fourth hand


    return 0;
} //end main
