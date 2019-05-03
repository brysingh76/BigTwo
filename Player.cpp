//
//  Player.cpp
//  DuecesCardGame
//


#include "Player.hpp"

//
//********************
//Default constructor*
//********************
//
Player::Player()
{
    //creates empty class
}

//
//*************************************
//OVERLOAD < operator for Player Class*
//*************************************
//
bool operator < (const Player& lhs, const Player& rhs)
{
    if (lhs.lowestCard < rhs.lowestCard)
    {
        return true;
    }
    return false; //(lhs.lowestCard.suitStrength < rhs.lowestCard.suitStrength);
    //return (lhs.cardNum == rhs.cardNum) && (lhs.suitStrength < rhs.suitStrength);
}

//
//***********************
//setPlayerName function*
//***********************
//
void setPlayerName(int numPlayers, Player& p1, Player& p2, Player& p3, Player& p4)
{
    switch(numPlayers)
    {
        case 2:
        {
            std::string nameOne, nameTwo;
            std::cout << "Player 1 please select a name." << std::endl;
            std::cin >> nameOne;
            std::cout << "Player 2 please select a name." << std::endl;
            std::cin >> nameTwo;
            //Set the names
            p1.playerName = nameOne;
            p2.playerName = nameTwo;
        }
        break;
        case 3:
        {
            std::string nameOne, nameTwo, nameThree;
            std::cout << "Player 1 please select a name." << std::endl;
            std::cin >> nameOne;
            std::cout << "Player 2 please select a name." << std::endl;
            std::cin >> nameTwo;
            std::cout << "Player 3 please select a name." << std::endl;
            std::cin >> nameThree;
            //set the names
            p1.playerName = nameOne;
            p2.playerName = nameTwo;
            p3.playerName = nameThree;
            std::cout << "IN setPlayerName function testing names. " << std::endl;
            std::cout << p1.playerName << std::endl;
            std::cout << p2.playerName << std::endl;
            std::cout << p3.playerName << std::endl;
        }
        break;
        case 4:
        {
            std::string nameOne, nameTwo, nameThree, nameFour;
            std::cout << "Player 1 please select a name." << std::endl;
            std::cin >> nameOne;
            std::cout << "Player 2 please select a name." << std::endl;
            std::cin >> nameTwo;
            std::cout << "Player 3 please select a name." << std::endl;
            std::cin >> nameThree;
            std::cout << "Player 4 please select a name." << std::endl;
            std::cin >> nameFour;
            //set the names
            p1.playerName = nameOne;
            p2.playerName = nameTwo;
            p3.playerName = nameThree;
            p4.playerName = nameFour;
        }
        break;
        default:
            std::cout << "Bang Bang error son!" << std::endl;
    }
}

//
//*******************
//passCards Function*
//*******************
//
void passCards(int numPlayers, std::vector<CardTemplate> deckOfCards, Player& p1, Player& p2, Player& p3, Player& p4)
{
    //Distribute cards to number of Players
    switch(numPlayers)
    {
        case 2:
        {
            for(int i = 0; i < deckOfCards.size() - 1; i++)
            {
                p1.playerHand.push_back(deckOfCards[i]);
                i++;
                p2.playerHand.push_back(deckOfCards[i]);
                i++;
                //Will not be used just to keep cards randomized for 2 players (Keep to let users select deck?)
                //playerThree.push_back(deckOfCards[i]);
            }
        }
            break;
        case 3:
            for(int i = 0; i < deckOfCards.size() - 1; i++)
            {
                p1.playerHand.push_back(deckOfCards[i]);
                i++;
                p2.playerHand.push_back(deckOfCards[i]);
                i++;
                p3.playerHand.push_back(deckOfCards[i]);
            }
            break;
        case 4:
            for(int i = 0; i < deckOfCards.size() - 1; i++)
            {
                p1.playerHand.push_back(deckOfCards[i]);
                i++;
                p2.playerHand.push_back(deckOfCards[i]);
                i++;
                p3.playerHand.push_back(deckOfCards[i]);
                i++;
                p4.playerHand.push_back(deckOfCards[i]);
            }
            break;
        default:
            std::cout << " There can only be 2-4 players! " << std::endl;
    }
}

//
//***************
//Print Function*
//***************
//
void printPlayerHand(Player& p1)
{
    //Display Player Hand
    for(int i = 0; i < p1.playerHand.size(); i++)
    {
        if(i >= 10)
        {
            std::cout << i << "."  << std::setw(8) << p1.playerHand[i].suit << " : " << std::setw(2) << p1.playerHand[i].cardNum << " " << std::endl;
        }
        else
        {
            std::cout << i << "."  << std::setw(9) << p1.playerHand[i].suit << " : " << std::setw(2) << p1.playerHand[i].cardNum << " " << std::endl;
        }
    }
    std::cout <<std::endl;
}

//
//******************************************
//arrangeCards Function (NEEDS IMPROVEMENT)*
//******************************************
//
void arrangeCardsFunc(int cardMoving, int cardEndLocation, Player& p1)
{
    iter_swap(p1.playerHand.begin() + cardMoving, p1.playerHand.begin() + cardEndLocation);
}

//
//***************************
//arrangePlayerHand Function*
//***************************
//
void arrangePlayerHand(Player& p1)
{
    //Bool to determine Player 1 is done arranging cards
    bool doneArranging = false;
    int cardMoving = 0;
    int cardEndLocation = 0;
    
    //Write end condition
    std::cout << "Once Done arranging type '666' " << std::endl;
    
    while(!doneArranging)
    {
        //Display Player Hand
        printPlayerHand(p1);
        std::cout << std::endl;
        
        //Request which card to move and where
        std::cout << " Which Card would you like to move? " << std::endl;
        std::cin >> cardMoving;
        //Check to see if user if done arranging their hand
        if(cardMoving == 666)
        {
            doneArranging = true;
        }
        else if(cardMoving > p1.playerHand.size() || cardMoving < 0)
        {
            std::cout << "That's not an option! " << std::endl;
            std::cout << "Out of range. " << std::endl;
        }
        else
        {
            std::cout << " Where would you like to place this card? " << std::endl;
            std::cin >> cardEndLocation;
            //Check to see if user if done arranging their hand
            if(cardEndLocation == 666)
            {
                doneArranging = true;
            }
            else if(cardEndLocation > p1.playerHand.size() || cardEndLocation < 0)
            {
                std::cout << "That's not an option! " << std::endl;
                std::cout << "Out of range. " << std::endl;
                std::cout << "Please enter another location to place the card. " << std::endl;
                while(cardEndLocation > p1.playerHand.size() || cardEndLocation < 0)
                {
                    std::cin >> cardEndLocation;
                }
                //Call cardArrangeFunction
                arrangeCardsFunc(cardMoving, cardEndLocation, p1);
            }
            else
            {
                //Call cardArrangeFunction
                arrangeCardsFunc(cardMoving, cardEndLocation, p1);
            }
        }
    }
}

//
//**************************
//selectHandToPlay Function*
//**************************
//
std::vector<CardTemplate> selectHandToPlay(Player& p1)
{
    //Dont ask for numCard but instead should be determined by start of round
    std::cout << "How many cards will you be playing?" << std::endl;
    int numCardsToPlay;
    std::cin >> numCardsToPlay;
    //Make sure numCardsToPlay is less than greater than 0 but less than 6.
    while(numCardsToPlay < 1 || numCardsToPlay > 5)
    {
        std::cout << "You can only choose 1 to 5 cards!" << std::endl;
        std::cin >> numCardsToPlay;
    }
    
    //CardTemplate for all possible selected card (5)
    CardTemplate cardOne;
    CardTemplate cardTwo;
    CardTemplate cardThree;
    CardTemplate cardFour;
    CardTemplate cardFive;
    
    //Ints to hold which card is selected in vector
    int card1;
    int card2;
    int card3;
    int card4;
    int card5;
    
    //Possible for loop instead of switch?
    switch(numCardsToPlay)
    {
        case 1: //If player chooses to throw a single
            std::cout << "Which one card would you like to play?" << std::endl;
            printPlayerHand(p1);
            std::cin.ignore() >> card1;
            cardOne = p1.playerHand[card1];
            p1.selectedHand.push_back(cardOne);
            return p1.selectedHand;
        case 2:
            std::cout << "Which two cards would you like to play?" << std::endl;
            printPlayerHand(p1);
            std::cin.ignore() >> card1;
            std::cin.ignore() >> card2;
            cardOne = p1.playerHand[card1];
            cardTwo = p1.playerHand[card2];
            p1.selectedHand.push_back(cardOne);
            p1.selectedHand.push_back(cardTwo);
            return p1.selectedHand;
        case 3:
            std::cout << "Which three cards would you like to play?" << std::endl;
            printPlayerHand(p1);
            std::cin.ignore() >> card1;
            std::cin.ignore() >> card2;
            std::cin.ignore() >> card3;
            cardOne = p1.playerHand[card1];
            cardTwo = p1.playerHand[card2];
            cardThree = p1.playerHand[card3];
            p1.selectedHand.push_back(cardOne);
            p1.selectedHand.push_back(cardTwo);
            p1.selectedHand.push_back(cardThree);
            return p1.selectedHand;
        case 4:
            std::cout << "Which four cards would you like to play?" << std::endl;
            printPlayerHand(p1);
            std::cin.ignore() >> card1;
            std::cin.ignore() >> card2;
            std::cin.ignore() >> card3;
            std::cin.ignore() >> card4;
            cardOne = p1.playerHand[card1];
            cardTwo = p1.playerHand[card2];
            cardThree = p1.playerHand[card3];
            cardFour = p1.playerHand[card4];
            p1.selectedHand.push_back(cardOne);
            p1.selectedHand.push_back(cardTwo);
            p1.selectedHand.push_back(cardThree);
            p1.selectedHand.push_back(cardFour);
            return p1.selectedHand;
        case 5:
            std::cout << "Which five cards would you like to play?" << std::endl;
            printPlayerHand(p1);
            std::cin.ignore() >> card1;
            std::cin.ignore() >> card2;
            std::cin.ignore() >> card3;
            std::cin.ignore() >> card4;
            std::cin.ignore() >> card5;
            cardOne = p1.playerHand[card1];
            cardTwo = p1.playerHand[card2];
            cardThree = p1.playerHand[card3];
            cardFour = p1.playerHand[card4];
            cardFive = p1.playerHand[card5];
            p1.selectedHand.push_back(cardOne);
            p1.selectedHand.push_back(cardTwo);
            p1.selectedHand.push_back(cardThree);
            p1.selectedHand.push_back(cardFour);
            p1.selectedHand.push_back(cardFive);
            return p1.selectedHand;
        default:
            std::cout << "There was an error in number of cards selected. " << std::endl;
            p1.selectedHand.clear();
            return p1.selectedHand;
    }
}

//
//*******************************************************
//searchLowestCard assistant Function for findLowestCard*
//*******************************************************
//
CardTemplate searchLowestCard(std::vector<CardTemplate> playerHand)
{
    //set large card template to test againt
    CardTemplate lowCard;
    lowCard.cardNum = 666;
    lowCard.suitStrength = 333;
    lowCard.suit = "SATAAN";
    
    //loop to see what is the lowest card
    for(int i = 0; i < playerHand.size(); i++)
    {
        if(playerHand[i] < lowCard)
        {
            lowCard = playerHand[i];
        }
    }
    std::cout << "END OF SEARCH in searchLowestCard" << std::endl;
    std::cout << "Lowest card is: " << lowCard.suit << " : " << lowCard.cardNum << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    return lowCard;
}

//
//*******************************************
//DetermineLowestCard Function for 2 Players*
//*******************************************
//
void determineLowestCard(Player& p1, Player& p2)
{
    //create structure to store who has lowest card and which it is
    lowCardStruct lowCardInPlay;
    if(p1.lowestCard < p2.lowestCard)
    {
        //set player one as 0 and player2 as 1
        p1.turnNumber = 0;
        p2.turnNumber = 1;
    }
    else
    {
        //Set playerTwo as 0 and playerOne as 1
        p2.turnNumber = 0;
        p1.turnNumber = 1;
    }
}

//
//*******************************************
//DetermineLowestCard Function for 3 Players**** sort not working?
//*******************************************
//
void determineLowestCard(Player& p1, Player& p2, Player& p3)
{
    std::vector<Player> playerVect;
    playerVect.push_back(p1);
    playerVect.push_back(p2);
    playerVect.push_back(p3);
    
    // < overloaded so this works fine
    std::sort(playerVect.begin(), playerVect.end());
    
    for (int i = 0; i < playerVect.size(); i++)
    {
        playerVect[i].turnNumber = i;
        if(p1.playerName == playerVect[i].playerName)
        {
            p1.turnNumber = playerVect[i].turnNumber;
        }
        if(p2.playerName == playerVect[i].playerName)
        {
            p2.turnNumber = playerVect[i].turnNumber;
        }
        if(p3.playerName == playerVect[i].playerName)
        {
            p3.turnNumber = playerVect[i].turnNumber;
        }
    }
}

//
//*******************************************
//DetermineLowestCard Function for 4 Players*
//*******************************************
//
void determineLowestCard(Player& p1, Player& p2, Player& p3, Player& p4)
{
    std::vector<Player> playerVect;
    playerVect.push_back(p1);
    playerVect.push_back(p2);
    playerVect.push_back(p3);
    playerVect.push_back(p4);
    
    // < overloaded so this works fine
    std::sort(playerVect.begin(), playerVect.end());
    
    for (int i = 0; i < playerVect.size(); i++)
    {
        playerVect[i].turnNumber = i;
        if(p1.playerName == playerVect[i].playerName)
        {
            p1.turnNumber = playerVect[i].turnNumber;
        }
        if(p2.playerName == playerVect[i].playerName)
        {
            p2.turnNumber = playerVect[i].turnNumber;
        }
        if(p3.playerName == playerVect[i].playerName)
        {
            p3.turnNumber = playerVect[i].turnNumber;
        }
        if(p4.playerName == playerVect[i].playerName)
        {
            p4.turnNumber = playerVect[i].turnNumber;
        }
    }
}

//
//************************
//findLowestCard Function*
//************************
//
void findLowestCard(int numPlayers, Player& p1, Player& p2, Player& p3, Player& p4)
{
    //Variables to hold each player's lowest card
    CardTemplate playerOneLowestCard;
    CardTemplate playerTwoLowestCard;
    CardTemplate playerThreeLowestCard;
    CardTemplate playerFourLowestCard;
    
    switch(numPlayers)
    {
        case 2:
            //2 Players search player1 and player2 vector
            p1.lowestCard = searchLowestCard(p1.playerHand);
            p2.lowestCard = searchLowestCard(p2.playerHand);
            //Determine who has lowest card calling determineLowest Function
            determineLowestCard(p1, p2);
            break;
        case 3:
            //3 Players search player1, player2, and player 3 vectors
            p1.lowestCard = searchLowestCard(p1.playerHand);
            p2.lowestCard = searchLowestCard(p2.playerHand);
            p3.lowestCard = searchLowestCard(p3.playerHand);
            //Determine Lowest card card calling determineLowest Function
            determineLowestCard(p1, p2, p3);
            break;
        case 4:
            //4 players, search player1, player2, player3, player4
            p1.lowestCard = searchLowestCard(p1.playerHand);
            p2.lowestCard = searchLowestCard(p2.playerHand);
            p3.lowestCard = searchLowestCard(p3.playerHand);
            p4.lowestCard = searchLowestCard(p4.playerHand);
            //Determine Lowest Card card calling determineLowest Function
            determineLowestCard(p1, p2, p3, p4);
            break;
        default:
            std::cout << "ERROR" << std::endl;
    }
}

//
//****************
//setPlayerVector*
//****************
//
std::vector<Player> setPlayerVector(int numPlayers, Player p1, Player p2, Player p3, Player p4)
{
    //SetPlayerOrder
    
    //Vector of Players
    std::vector<Player> playerVect;
    
    //Place numPlayers into playerVect which contains all players
    switch(numPlayers)
    {
        case 2:
            playerVect.push_back(p1);
            playerVect.push_back(p2);
            return playerVect;
        case 3:
            playerVect.push_back(p1);
            playerVect.push_back(p2);
            playerVect.push_back(p3);
            return playerVect;
        case 4:
            playerVect.push_back(p1);
            playerVect.push_back(p2);
            playerVect.push_back(p3);
            playerVect.push_back(p4);
            return playerVect;
    }
    playerVect.erase(playerVect.begin(), playerVect.end());
    return playerVect;
}







