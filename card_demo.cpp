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

    while(1)
    {
        if(d.size() == 0)
        {
            cout << "Game over\n";
            break;
        }
        if(p1.getHandSize()>0) {
            Card c1 = p1.chooseCardFromHand();
            cout << p1.getName() << " asking for " << c1.toString() << "\n";
            if (p2.cardInHand(c1)) {
                p1.addCard(p2.removeCardFromHand(c1));
            } else {
                p1.addCard(d.dealCard());
            }
        } else {
            cout << "No cards, so " << p1.getName() << " is drawing\n";
            p1.addCard(d.dealCard());
        }
        if(d.size() == 0)
        {
            cout << "Game over\n";
            break;
        }
        if(p2.getHandSize()> 0) {
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
        }
        else {
            cout << "No cards, so " << p2.getName() << " is drawing\n";
            p2.addCard(d.dealCard());
        }
        cout << p1.getName() <<" has : \n" << p1.showHand() << endl;
        cout << p1.getName() <<" has books : \n" << p1.showBooks() << endl;
        cout << p2.getName() <<" has : \n" << p2.showHand() << endl;
        cout << p2.getName() <<" has books : \n" << p2.showBooks() << endl;
    }
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   


