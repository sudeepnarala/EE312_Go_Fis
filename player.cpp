//
// Created by Sudeep Narala on 10/25/18.
//

#include "player.h"
#include <vector>
#include <cstdlib>

Player::Player()
{
    myName = "";
}

void Player::addCard(Card c)
{
    myHand.push_back(c);
    Card::Card* card1 = new Card::Card();
    Card::Card* card2 = new Card::Card();
    while(this->checkHandForBook(*card1, *card2))
    {
        this->bookCards(*card1, *card2);
    }
    delete(card1);
    delete(card2);
}

void Player::bookCards(Card c1, Card c2)
{
    this->removeCardFromHand(c1);
    this->removeCardFromHand(c2);
    myBook.push_back(c1);
    myBook.push_back(c2);
}
// Precondition: There is at least one card in the hand
Card Player::chooseCardFromHand()
{
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    int index = rand()%myHand.size();
    return myHand.at(index);
}

bool Player::cardInHand(Card c) const
{
    for(vector<Card>::const_iterator  i=myHand.begin(); i!=myHand.end(); ++i)
    {
        if((*i).getRank()==c.getRank())
        {
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c)
{
    int index = 0;
    for(vector<Card>::const_iterator i=myHand.begin(); i!=myHand.end(); ++i)
    {
        if((*i).getRank()==c.getRank())
        {
            Card temp = *i;
            myHand.erase(myHand.begin()+index);
            return temp;
        }
        index++;
    }
    return *(new Card::Card());
}

int Player::getHandSize() const
{
    int c=0;
    for(vector<Card>::const_iterator i=myHand.begin(); i!=myHand.end(); ++i)
    {
        c++;
    }
    return c;
}

int Player::getBookSize() const
{
    int c=0;
    for(vector<Card>::const_iterator i=myBook.begin(); i!=myBook.end(); ++i)
    {
        c++;
    }
    return c;
}

string Player::showHand() const
{
    string str = "";
    for(vector<Card>::const_iterator i=myHand.begin(); i!=myHand.end(); ++i)
    {
        str+=(*i).toString();
        str+="\n";
    }
    return str;
}

string Player::showBooks() const
{
    string str = "";
    for(vector<Card>::const_iterator i=myBook.begin(); i!=myBook.end(); ++i)
    {
        str+=(*i).toString();
        str+="\n";
    }
    return str;
}

bool Player::checkHandForBook(Card &c1, Card &c2)
{
    for(vector<Card>::const_iterator i=myHand.begin(); i!=myHand.end(); ++i) {
        for (vector<Card>::const_iterator j = i+1; j != myHand.end(); ++j) {
            if ((*i).getRank() == (*j).getRank()) {
                Card* temp = new Card::Card((*i).getRank(), (*i).getSuit());
                Card* temp2 = new Card::Card((*j).getRank(), (*j).getSuit());
                c1 = *temp;
                c2 = *temp2;
                delete(temp);
                delete(temp2);
                return true;
            }
        }
    }
    return false;
}