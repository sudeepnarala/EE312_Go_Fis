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
    else if(myRank==2)
    {
        rankStr = "2";
    }
    else if(myRank==3)
    {
        rankStr = "3";
    }
    else if(myRank==4)
    {
        rankStr = "4";
    }
    else if(myRank==5)
    {
        rankStr = "5";
    }
    else if(myRank==6)
    {
        rankStr = "6";
    }
    else if(myRank==7)
    {
        rankStr = "7";
    }
    else if(myRank==8)
    {
        rankStr = "8";
    }
    else if(myRank==9)
    {
        rankStr = "9";
    }
    else if(myRank==10)
    {
        rankStr = "10";
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
//    else if(myRank==10) {
//        rankStr = "10";
//    }
// Method using C-Strings
//    else
//    {
//        char rankStrtemp[2];
//        rankStrtemp[0] = myRank+48;
//        rankStrtemp[1] = '\0';
//        std::string copystr(rankStrtemp);
//        rankStr = copystr;
//    }
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
    else if(r==2)
    {
        rankStr = "2";
    }
    else if(r==3)
    {
        rankStr = "3";
    }
    else if(r==4)
    {
        rankStr = "4";
    }
    else if(r==5)
    {
        rankStr = "5";
    }
    else if(r==6)
    {
        rankStr = "6";
    }
    else if(r==7)
    {
        rankStr = "7";
    }
    else if(r==8)
    {
        rankStr = "8";
    }
    else if(r==9)
    {
        rankStr = "9";
    }
    else if(r==10)
    {
        rankStr = "10";
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
//    else if(r==10)
//    {
//        rankStr = "10";
//    }
//    else
//    {
//        char rankStrtemp[2];
//        rankStrtemp[0] = myRank+48;
//        rankStrtemp[1] = '\0';
//        std::string copystr(rankStrtemp);
//        rankStr = copystr;
//    }
    return rankStr;
}

bool Card::operator!=(const Card &rhs) const
{
    return (myRank!=rhs.getRank()) || (mySuit!=rhs.getSuit());
}

bool Card::operator==(const Card &rhs) const
{
    return (myRank==rhs.getRank()) && (mySuit==rhs.getSuit());
}

Card::Suit Card::getSuit() const
{
    return mySuit;
}