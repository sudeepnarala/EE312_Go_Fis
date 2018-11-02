//
// Created by Sudeep Narala on 10/25/18.
//

#include "card.h"
#include <string>

Card::Card()
{
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s)
{
    myRank = rank;
    mySuit = s;
}

string Card::toString() const
{
    string rankStr = "";
    string suitStr = "";
    if(mySuit==spades)
        suitStr = "s";
    else if(mySuit==hearts)
        suitStr = "h";
    else if(mySuit==diamonds)
        suitStr = "d";
    else
        suitStr = "c";
    if(myRank==1)
    {
        rankStr = "A";
    }
    else if(myRank==11)
    {
        rankStr = "J";
    }
    else if(myRank==12)
    {
        rankStr = "Q";
    }
    else if(myRank==13)
    {
        rankStr = "K";
    }
    else
    {
        rankStr = std::to_string(myRank);
    }
    return rankStr + suitStr;
}

bool Card::sameSuitAs(const Card &c) const
{
    return (mySuit == c.mySuit);
}

int Card::getRank() const
{
    return myRank;
}

string Card::suitString(Card::Suit s) const
{
    string suitStr = "";
    if(s==spades)
        suitStr = "s";
    else if(s==hearts)
        suitStr = "h";
    else if(s==diamonds)
        suitStr = "d";
    else
        suitStr = "c";
    return suitStr;
}

string Card::rankString(int r) const
{
    string rankStr = "";
    if(r==1)
    {
        rankStr = "A";
    }
    else if(r==11)
    {
        rankStr = "J";
    }
    else if(r==12)
    {
        rankStr = "Q";
    }
    else if(r==13)
    {
        rankStr = "K";
    }
    else
    {
        rankStr = std::to_string(myRank);
    }
    return rankStr;
}

bool Card::operator!=(const Card &rhs) const
{
    return myRank!=rhs.getRank();
}

bool Card::operator==(const Card &rhs) const
{
    return myRank==rhs.getRank();
}

Card::Suit Card::getSuit() const
{
    return mySuit;
}