//
//  CardTemplate.h
//  DuecesCardGame
//


#ifndef CardTemplate_hpp
#define CardTemplate_hpp

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class CardTemplate
{
    public:
    //Add another int for cardStrength and number all card based on str 0-51. 0 = 3 diamond and 51 = 2 spade
    std::string suit;
    int suitStrength;
    int cardNum;
    //int cardStrength;
    //potentially add string for 11+ cardNum instead of ints
    friend std::ostream& operator<<(std::ostream& os, const CardTemplate& card);

};

struct lowCardStruct
{
    //change int to pointer and add 4 pointers
    std::vector<CardTemplate>* playerA;
    std::vector<CardTemplate>* playerB;
    std::vector<CardTemplate>* playerC;
    std::vector<CardTemplate>* playerD;
    int playerWithLowCard;
    CardTemplate lowestCard;
};

//**************
//FreeFunctions*
//**************

//Overload < operator
bool operator < (const CardTemplate& lhs, const CardTemplate& rhs);

//Setting suit function for 4 suits
void setSuit(std::vector<CardTemplate> &suitCards, std::string suit, int suitStr);

//Counting number of card function
long countCards(std::vector<CardTemplate>& cardsVector);

//displayHandToBeat
void displayHandToBeat(std::vector<CardTemplate> handToBeat);



#endif /* CardTemplate_hpp */
