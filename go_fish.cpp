// FILE: card_demo.cpp
// This is a small demonstration program showing how the bag class is used.
#include <iostream>    // Provides fishFile and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main()
{
    ofstream fishFile("gofish_results.txt");
    if(!fishFile.is_open())
    {
        fishFile << "Failed to open file\n";
        return 1;
    }
    int numCards = 7;

    Player p1("Joe");
    Player p2("Hannah");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    Card* c1 = new Card();
    Card* c2 = new Card();
    Card* playerOneCard = new Card();
    Card* playerTwoCard = new Card();
    while((p1.getHandSize() + p2.getHandSize()) != 0)
    {
        bool here1 = false;
        bool here2 = false;
        if(p1.getHandSize()>0) {
            *playerOneCard = p1.chooseCardFromHand();
            fishFile << p1.getName() << " asks - Do you have a " << (*playerOneCard).rankString((*playerOneCard).getRank())
                 << endl;
        }
        else
        {
            // if reach here, deck has cards
            Card dealCard = d.dealCard();
            fishFile << p1.getName() << " draws " << dealCard.rankString(dealCard.getRank());
            fishFile << '\n';
            p1.addCard(dealCard);
            here1 = true;
        }
        if(!here1) {
            while (p2.cardInHand(*playerOneCard)) {
                fishFile << p2.getName() << " saying - Yes. I have a " << (*playerOneCard).rankString((*playerOneCard).getRank())
                     << endl;
                p1.addCard(p2.removeCardFromHand(*playerOneCard));
                p1.checkHandForBook(*c1, *c2);
                fishFile << p1.getName() << " books " << (*playerOneCard).rankString((*playerOneCard).getRank()) << endl;
                fishFile << '\n';
                if (p1.getHandSize() > 0) {
                    *playerOneCard = p1.chooseCardFromHand();
                    fishFile << p1.getName() << " asks - Do you have a "
                         << (*playerOneCard).rankString((*playerOneCard).getRank())
                         << endl;
                } else {
                    if (d.size() != 0) {
                        Card dealCard = d.dealCard();
                        fishFile << p1.getName() << " draws " << dealCard.rankString(dealCard.getRank());
                        fishFile << '\n';
                        p1.addCard(dealCard);
                        break;
                    } else {
                        goto ending;
                    }
                }
            }
            fishFile << p2.getName() << " says - Go fish" << endl;
            if (d.size() != 0) {
                Card drawCard = d.dealCard();
                fishFile << p1.getName() << " draws " << (*playerOneCard).rankString(drawCard.getRank()) << endl;
                fishFile << '\n';
                p1.addCard(drawCard);
            }
        }
        // _________ //
        if(p2.getHandSize() > 0) {
            (*playerTwoCard) = p2.chooseCardFromHand();
            fishFile << p2.getName() << " asks - Do you have a " << (*playerTwoCard).rankString((*playerTwoCard).getRank())
                 << endl;
        }
        else {
            if(d.size()>0) {
                // if reach here, deck has cards
                Card dealCard = d.dealCard();
                fishFile << p2.getName() << " draws " << dealCard.rankString(dealCard.getRank());
                fishFile << '\n';
                p2.addCard(dealCard);
                here2 = true;
            } else{
                goto ending;
            }
        }
        if(!here2) {
            while (p1.cardInHand(*playerTwoCard)) {
                fishFile << p1.getName() << " says - Yes. I have a " << (*playerTwoCard).rankString((*playerTwoCard).getRank())
                     << endl;
                p2.addCard(p1.removeCardFromHand(*playerTwoCard));
                p2.checkHandForBook(*c1, *c2);
                fishFile << p2.getName() << " books " << (*playerTwoCard).rankString((*playerTwoCard).getRank()) << endl;
                fishFile << '\n';
                if (p2.getHandSize() > 0) {
                    (*playerTwoCard) = p2.chooseCardFromHand();
                    fishFile << p2.getName() << " asks - Do you have a "
                         << (*playerTwoCard).rankString((*playerTwoCard).getRank())
                         << endl;
                } else {
                    if (d.size() != 0) {
                        Card dealCard = d.dealCard();
                        fishFile << p2.getName() << " draws " << dealCard.rankString(dealCard.getRank()) << endl;
                        fishFile << '\n';
                        p2.addCard(dealCard);
                        break;
                    } else {
                        goto ending;
                    }
                }
            }
            fishFile << p1.getName() << " say - Go fish" << endl;
            if (d.size() != 0) {
                Card drawCard = d.dealCard();
                fishFile << p2.getName() << " draws " << (*playerTwoCard).rankString(drawCard.getRank()) << endl;
                fishFile << '\n';
                p2.addCard(drawCard);
            }
        }

    }

    ending:    fishFile << p1.getName() <<" has books : \n" << p1.showBooks() << endl;
    fishFile << p2.getName() <<" has books : \n" << p2.showBooks() << endl;
    if(p1.getBookSize() > p2.getBookSize())
    {
        fishFile << p1.getName() << " wins with " << p1.getBookSize()/2 << " books!" << endl;
    }

    else if(p2.getBookSize() > p1.getBookSize())
    {
        fishFile << p2.getName() << " wins with " << p2.getBookSize()/2 << " books!" << endl;
    }
    else
    {
        fishFile << "It is a tie, both players have " << p1.getBookSize()/2 << " books!" << endl;
    }
    fishFile.close();
    delete(c1);
    delete(c2);
    delete(playerOneCard);
    delete(playerTwoCard);
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}


   


