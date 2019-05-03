//
//  main.cpp
//  DuecesCardGame
//


#include "CardTemplate.hpp"
#include "Player.hpp"
#include <ctime>
#include <string>

//Overload << operator

//
//**************
//Main Function*
//**************
//
int main()
{
    //Number of cards in suit for Vector
    const int cardsPerSuit = 13;

    //Holds all Diamond cards
    std::vector<CardTemplate> diamondSuit(cardsPerSuit);
    //set Diamond Cards
    setSuit(diamondSuit, "Diamond", 0);
    
    //Holds all Clover cards
    std::vector<CardTemplate> cloverSuit(cardsPerSuit);
    //set Clover Cards
    setSuit(cloverSuit, "Clover", 1);
    
    //Holds all Heart cards
    std::vector<CardTemplate> heartSuit(cardsPerSuit);
    //set Heart Cards
    setSuit(heartSuit, "Heart", 2);
    
    //Holds all Spade cards
    std::vector<CardTemplate> spadeSuit(cardsPerSuit);
    //set Spade Cards
    setSuit(spadeSuit, "Spade", 3);
    
    //Vector holding all cards (52)
    std::vector<CardTemplate> deckOfCards;
    
    //Creating vector to hold all cards
    deckOfCards.reserve(diamondSuit.size() + cloverSuit.size() + heartSuit.size() + spadeSuit.size());
    deckOfCards.insert(deckOfCards.end(), diamondSuit.begin(), diamondSuit.end());
    deckOfCards.insert(deckOfCards.end(), cloverSuit.begin(), cloverSuit.end());
    deckOfCards.insert(deckOfCards.end(), heartSuit.begin(), heartSuit.end());
    deckOfCards.insert(deckOfCards.end(), spadeSuit.begin(), spadeSuit.end());
    
    //random number
    //int randNum;
    
    //seed randomNum generator
    //srand(time(NULL));
    //randNum = rand();
    
    //Shuffle Deck of Cards (NEEDS IMPROVEMENT) use std::shuffle with rand num generator
    std::random_shuffle(deckOfCards.begin(), deckOfCards.end());
    std::random_shuffle(deckOfCards.begin(), deckOfCards.end());
    std::random_shuffle(deckOfCards.begin(), deckOfCards.end());
    //std::random_shuffle(deckOfCards.begin(), deckOfCards.end());
    //std::random_shuffle(deckOfCards.begin(), deckOfCards.end());
    std::random_shuffle(deckOfCards.begin(), deckOfCards.end());

    
    //std::shuffle(deckOfCards.begin(), deckOfCards.end(), randNum)
    
    //Number of players (vectors to pass cards to)
    int numPlayers;
    
    std::cout << "How many players? " << std::endl;
    std::cin >> numPlayers;
    
    //Create an instance of class player for each person playing
    Player p1;
    Player p2;
    Player p3;
    Player p4;
    
    //Allow players to name themselves
    setPlayerName(numPlayers, p1, p2, p3, p4);
    
    //Pass out cards to the number of players
    passCards(numPlayers, deckOfCards, p1, p2, p3, p4);
    
    //************************************
    //Allow player to arrange their cards*** change to func and numplayers add
    //************************************
    std::cout << " Player 1 please arrange your cards " << std::endl;
    //arrangePlayerHand(p1);
    
    //******************************************
    //Determine who has Lowest card to go first****Fix
    //******************************************
    std::cout << "Checking for who has lowest card " << std::endl;
    std::cout << std::endl;
    //Determine what the lowestCard is and who has it. Return struct ptr of remaining players
    findLowestCard(numPlayers, p1, p2, p3, p4);
    
    //************************************************************
    //Let the player decide what cards to use w/ switch statement*
    //************************************************************
    std::cout << "Testing who goes first. " << std::endl;
    
    //Pointers for order players play
    Player* playerA;
    Player* playerB;
    Player* playerC;
    Player* playerD;
    
    //Vector to hold all the players
    std::vector<Player> playerVect;
    
    //Function to add all the players into the vector
    playerVect = setPlayerVector(numPlayers, p1, p2, p3, p4);
    
    //
    //************************************************
    //Set the actual player turn based on num players*
    //************************************************
    //
    switch(numPlayers)
    {
        case 2:
            for(int i = 0; i < playerVect.size(); i++)
            {
                if(playerVect[i].turnNumber == 0)
                {
                    playerA = &playerVect[i];
                }
                else
                {
                    playerB = &playerVect[i];
                }
            }
            break;
        case 3:
            for(int i = 0; i < playerVect.size(); i++)
            {
                if(playerVect[i].turnNumber == 0)
                {
                    std::cout << playerVect[i].playerName << std::endl;
                    playerA = &playerVect[i];
                }
                else if(playerVect[i].turnNumber == 1)
                {
                    playerB = &playerVect[i];
                }
                else if (playerVect[i].turnNumber == 2)
                {
                    playerC = &playerVect[i];
                }
                else
                {
                    std::cout << "Error in the Main() switch statement.";
                }
            }
            break;
        case 4:
            for(int i = 0; i < playerVect.size(); i++)
            {
                if(playerVect[i].turnNumber == 0)
                {
                    std::cout << "PLAYER: " << playerVect[i].playerName << std::endl;
                    playerA = &playerVect[i];
                }
                else if(playerVect[i].turnNumber == 1)
                {
                    playerB = &playerVect[i];
                }
                else if(playerVect[i].turnNumber == 2)
                {
                    playerC = &playerVect[i];
                }
                else
                {
                    playerD = &playerVect[i];
                }
            }
            break;
        default:
            std::cout << "ERROR in order switch" << std::endl;
    }
    
    //
    //Display who is starting first
    //
    
    std::cout << "Player " << playerA->playerName << " please make your move." << std::endl;
    //std::cout << "Because your lowest card is: " << playerA->lowestCard.cardNum << " : " << playerA-> lowestCard.suit;
    
    std::cout << "Player B: " << playerB->playerName << std::endl;
    //std::cout << "Player C: " << playerC->playerName << std::endl;
    //std::cout << "Player D: " << playerD->playerName << std::endl;

    
    ///
    ///
    ///Game Rules Test 1 card each, 2 players
    ///Make sure working on actually playerX vector.
    ///Under heavy fuckin construction
    ///
    ///
    bool gameOver = false;
    bool startRound = true;
    std::vector<CardTemplate> handToBeat;
    while(gameOver == false)
    {
        std::sort(playerVect.begin(),playerVect.end());
        for(int i = 0; i < playerVect.size(); i++)
        {
            if(startRound != true)
            {
                //Delete cards from previous player's hand
                
                //displayHandToBeat
                displayHandToBeat(handToBeat);
                //ask user if they want to pass based on displayed handToBeat
                std::cout << "Would You like to pass? Y/N" << std::endl;
                char yesNo;
                std::cin >> yesNo;
                yesNo = toupper(yesNo);
                if(yesNo == 'Y')
                {
                    playerVect[i].pass = true;
                }
            }
            if(startRound == true)
            {
                playerVect[0].selectedHand = selectHandToPlay(playerVect[0]);
                handToBeat = playerVect[0].selectedHand;
                startRound = false;
            }
            else
            {
                //Next player selects their card
                playerVect[i].selectedHand = selectHandToPlay(playerVect[i]);
                //
                //COMPARE CARDS FUNCTION
                //
                
                //int or unsigned long? hand to beat is unsigned long
                unsigned long numCardsToBeat;
                numCardsToBeat = handToBeat.size();
                
                //compare this hand to handToBeat
                //Pass into Function selected hand, and handToBeat
                if(handToBeat.size() == 1)
                {
                    //Reusable error messages, turn to function?
                    while(playerVect[i].selectedHand.size() != handToBeat.size())
                    {
                        std::cout << "You dont have enough cards to beat the hand!" << std::endl;
                        playerVect[i].selectedHand = selectHandToPlay(playerVect[i]);
                    }
                    if(playerVect[i].selectedHand[0] < handToBeat[0])
                    {
                        std::cout << "That card is not strong enough!" << std::endl;
                        playerVect[i].selectedHand = selectHandToPlay(playerVect[i]);
                    }
                    else
                    {
                        handToBeat = playerVect[i].selectedHand;
                        //Remove selected hand from the new player
                        //First cycle through the playerHand because it's bigger
                        int k = 0;
                        for(int j = 0; j < playerVect[i].playerHand.size(); j++)
                        {
                            //If hand to beat == the cards in your deck delete them
                            if(handToBeat[k].cardNum == playerVect[i].playerHand[j].cardNum && handToBeat[k].suitStrength == playerVect[i].playerHand[j].suitStrength)
                            {
                                playerVect[i].playerHand.erase(playerVect[i].playerHand.begin() + i);
                            }
                        }
                    }
                }
            }
            std::cout << playerVect[i].playerName << std::endl;
            std::cout << "size of selected hand: " << playerVect[i].selectedHand.size() << std::endl;
            for(int j = 0; j < playerVect[i].selectedHand.size(); j++)
            {
                std::cout << playerVect[i].selectedHand[j] << std::endl;
            }
        }
    }
}
