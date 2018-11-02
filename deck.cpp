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
        myCards[i] = *(new Card(currRank, s));
        currRank+=1;
    }
    myIndex = -1;
}

void Deck::shuffle()
{
    srand((unsigned)time(0));
    for(int i=0; i<3*Deck::SIZE; i++)
    {
        int swapIndex = rand()%Deck::SIZE;
        Card temp = myCards[i%Deck::SIZE];
        myCards[i%Deck::SIZE] = myCards[swapIndex];
        myCards[swapIndex] = temp;
    }
}

// Precondition: There are cards left in the deck
Card Deck::dealCard()
{
    myIndex++;
    return myCards[myIndex];

}

int Deck::size() const
{
    return SIZE - myIndex;
}