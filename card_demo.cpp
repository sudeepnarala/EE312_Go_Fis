// FILE: card_demo.cpp
// This is a small demonstration program showing how the bag class is used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.cpp"
#include "player.cpp"
#include "deck.cpp"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : \n" << p1.showHand() << endl;
    cout << p2.getName() <<" has : \n" << p2.showHand() << endl;

    Card::Card* check5 = new Card::Card();
    Card::Card* check6 = new Card::Card();
    while(p1.checkHandForBook(*check5, *check6))
    {
        p1.bookCards(*check5, *check6);
    }
    while(p2.checkHandForBook(*check5, *check6))
    {
        p2.bookCards(*check5, *check6);
    }

    for(int i=0; i<3; i++)
    {
        Card c1 = p1.chooseCardFromHand();
        Card::Card* check1 = new Card::Card();
        Card::Card* check2 = new Card::Card();
        cout << p1.getName() << " asking for " << c1.toString() << "\n";
        if(p2.cardInHand(c1))
        {
            p1.addCard(p2.removeCardFromHand(c1));
        }
        else
        {
            p1.addCard(d.dealCard());
        }
        while(p1.checkHandForBook(*check1, *check2))
        {
            p1.bookCards(*check1, *check2);
        }
        Card c2 = p2.chooseCardFromHand();
        cout << p2.getName() << " asking for " << c2.toString() << "\n";
        if(p1.cardInHand(c2))
        {
            p2.addCard(p1.removeCardFromHand(c2));
        }
        else
        {
            p2.addCard(d.dealCard());
        }
        while(p2.checkHandForBook(*check1, *check2))
        {
            p2.bookCards(*check1, *check2);
        }
        cout << p1.getName() <<" has : \n" << p1.showHand() << endl;
        cout << p2.getName() <<" has : \n" << p2.showHand() << endl;
    }
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   


