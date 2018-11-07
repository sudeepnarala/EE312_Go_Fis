//
// Created by Sudeep Narala on 10/25/18.
//

#include "deck.h"
#include "card.h"
#include <cstdlib>

Deck::Deck()
{
    Card::Suit s = Card::spades;
    int currRank = 1;
    for(int i=0; i<Deck::SIZE; i++)
    {
        if(currRank==14)
        {
            currRank=1;
            if(s==Card::spades)
            {
                s = Card::hearts;
            }
            else if(s==Card::hearts)
            {
                s = Card::diamonds;
            }
            else if(s==Card::diamonds)
            {
                s = Card::clubs;
            }
        }
        Card* temp = new Card(currRank, s);
        myCards[i] = *temp;
        currRank+=1;
        delete(temp);
    }
    myIndex = Deck::SIZE;
}

void Deck::shuffle()
{
    srand((unsigned)time(0));
    for(int i=0; i<3*this->size(); i++)
    {
        int swapIndex = rand()%this->size();
        Card temp = myCards[i%this->size()];
        myCards[i%this->size()] = myCards[swapIndex];
        myCards[swapIndex] = temp;
    }
}

// Precondition: There are cards left in the deck
Card Deck::dealCard()
{
    myIndex--;
    if(myIndex >= 0) {
        return myCards[myIndex];
    } else{     // Should technically never come here
        Card* temp = new Card();
        Card temp2 = *temp;
        delete(temp);
        return temp2;
    }
}

int Deck::size() const
{
    return myIndex;
}