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
}

void Player::bookCards(Card c1, Card c2)
{
    this->removeCardFromHand(c1);
    this->removeCardFromHand(c2);
    myBook.push_back(c1);
    myBook.push_back(c2);
}
Card Player::chooseCardFromHand()
{
//    for(auto i=myHand.begin(); i!=myHand.end(); ++i)
//    {
//        bool flag = false;
//        for(auto j=asked.begin(); j!=asked.end(); ++j)
//        {
//            if((*i)==(*j))
//            {
//                flag=true;
//            }
//        }
//        if(flag)
//        {
//            continue;
//        }
//        else
//        {
//            asked.push_back(*i);
//            return (*i);
//        }
//    }
//    int len = this->getHandSize();
//    for(auto j=asked.begin(); j!=asked.end(); ++j)
//    {
//        len--;
//    }
//    if(len==0)
//        asked.empty();
//    asked.push_back(*myHand.begin());
//    return *myHand.begin();
    srand((unsigned)time(0));
    int index = rand()%myHand.size();
    return myHand.at(index);
}

bool Player::cardInHand(Card c) const
{
    for(auto i=myHand.begin(); i!=myHand.end(); ++i)
    {
        if(*i==c)
        {
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c)
{
    for(auto i=myHand.begin(); i!=myHand.end(); ++i)
    {
        if(*i==c)
        {
            Card temp = *i;
            myHand.erase(i);
            return temp;
        }
    }
    return *(new Card::Card());
}

int Player::getHandSize() const
{
    int c=0;
    for(auto i=myHand.begin(); i!=myHand.end(); ++i)
    {
        c++;
    }
    return c;
}

int Player::getBookSize() const
{
    int c=0;
    for(auto i=myBook.begin(); i!=myBook.end(); ++i)
    {
        c++;
    }
    return c;
}

string Player::showHand() const
{
    string str = "";
    for(auto i=myHand.begin(); i!=myHand.end(); ++i)
    {
        str+=(*i).toString();
        str+="\n";
    }
    return str;
}

string Player::showBooks() const
{
    string str = "";
    for(auto i=myBook.begin(); i!=myBook.end(); ++i)
    {
        str+=(*i).toString();
        str+="\n";
    }
    return str;
}

bool Player::checkHandForBook(Card &c1, Card &c2)
{
    for(auto i=myHand.begin(); i!=myHand.end(); ++i) {
        for (auto j = i+1; j != myHand.end(); ++j) {
            if ((*i) == (*j)) {
                c1 = *(new Card::Card((*i).getRank(), (*i).getSuit()));
                c2 = *(new Card::Card((*j).getRank(), (*j).getSuit()));
                return true;
            }
        }
    }
    return false;
}