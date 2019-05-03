//
//  Player.hpp
//  DuecesCardGame
//


#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <vector>
#include "CardTemplate.hpp"

//class CardTemplate;

class Player
{
public:
    //All of Player's Cards
    std::vector <CardTemplate> playerHand;
    std::vector <CardTemplate> selectedHand;
    std::string playerName;
    int turnNumber;
    bool pass = false;
    CardTemplate lowestCard;
    int numCardLeft = playerHand.size();
    
    //Default constructor
    Player();
};
//Overload < for PlayerClass ***** FIX THIS SHIT
bool operator < (const Player& lhs, const Player& rhs);

//setPlayerName function
void setPlayerName(int numPlayers, Player& p1, Player& p2, Player& p3, Player& p4);

//passCards Function (fixed with forward declaration?
void passCards(int numPlayers, std::vector<CardTemplate> deckOfCards, Player& p1, Player& p2, Player& p3, Player& p4);

//arrangePlayerHand Function
void arrangePlayerHand(Player& p1);

//Print Function
void PrintPlayerHand(Player& p1);

//arrangeCards Function (NEEDS IMPROVEMENT)
void arrangeCardsFunc(int cardMoving, int cardEndLocation, Player& p1);

//findLowestCard Function
void findLowestCard(int numPlayers, Player& p1, Player& p2, Player& p3, Player& p4);

//selectHandToPlay function for given hand
std::vector<CardTemplate> selectHandToPlay(Player& p1);

//searchLowestCard assistant Function for findLowestCard
CardTemplate searchLowestCard(std::vector<CardTemplate> playerHand);

//DetermineLowestCard Function for 2 Players
void determineLowestCard(Player& p1, Player& p2);

//DetermineLowestCard Function for 3 Players
void determineLowestCard(Player& p1, Player& p2, Player& p3);

//DetermineLowestCard Function for 4 Players
void determineLowestCard(Player& p1, Player& p2, Player& p3, Player& p4);

//setPlayerVect to place all player objects into vector and return
std::vector<Player> setPlayerVector(int numPlayers, Player p1, Player p2, Player p3, Player p4);

//setPlayerTurnNum sets the turn number


#endif /* Player_hpp */
