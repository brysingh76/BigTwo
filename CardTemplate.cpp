//
//  CardTemplate.cpp
//  DuecesCardGame
//


#include "CardTemplate.hpp"

//
//*******************************************
//OVERLOAD < Operator for CardTemplate Class*
//*******************************************
//
bool operator < (const CardTemplate& lhs, const CardTemplate& rhs) //left hand side vs right handside
{
    if (lhs.cardNum < rhs.cardNum)
    {
        return true;
    }
    return (lhs.cardNum == rhs.cardNum) && (lhs.suitStrength < rhs.suitStrength);
}

//
//**************************
//OVERLOAD << Operator cout*
//**************************
//
std::ostream& operator<<(std::ostream& os, const CardTemplate& card)
{
    os << card.suit << " : " << card.cardNum << std::endl;
    return os;
}

//
//********************
//countCards Function*
//********************
//
long countCards(std::vector<CardTemplate>& cardsVector)
{
    long numCards;
    numCards = cardsVector.size();
    return numCards;
}

//
//*****************
//setSuit Function*
//*****************
//
void setSuit(std::vector<CardTemplate> &suitCards, std::string suit, int suitStr)
{
    //For card Number lowest card is 3
    int j = 3;
    
    //Sets the suit/suitStr/num (properties of class)
    for(int i = 0; i < 13; i ++)
    {
        suitCards[i].suit = suit;
        suitCards[i].suitStrength = suitStr;
        suitCards[i].cardNum = j;
        j++;
    }
}

//
//******************
//displayHandToBeat*
//******************
//
void displayHandToBeat(std::vector<CardTemplate> handToBeat)
{
    for(int i = 0; i < handToBeat.size(); i++)
    {
        std::cout << handToBeat[i];
    }
}



