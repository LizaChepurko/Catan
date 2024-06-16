/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include "Catan.hpp"

Catan *Catan::instance = nullptr;

void Catan::initialize(player &p1, player &p2, player &p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

// The first player will have the higher dice result
void Catan::ChooseStartingPlayer()
{
    int n1 = p1.rollDice();
    int n2 = p2.rollDice();
    int n3 = p3.rollDice();
    int max = n1;
    max = max > n2 ? max : n2;
    max = max > n3 ? max : n3;
    player::game_started = true;
}

// Invokes the Board class and prints the resulting map
Board Catan::getBoard()
{
    Board board;
    for (int i = 0; i < 19; i++)
    {
        cout << board.block[i].serial << ": " << board.block[i].ResourceType << ", " << board.block[i].productivity << endl;
    }
    return board;
}

void Catan::printwinner()
{
    if (player::game_started == false)
    {
        for (size_t i = 0; i < player::players.size(); i++)
        {
            if (player::players[i]->getPoints() == 10)
            {
                cout << player::players[i] << " is the winner!" << endl;
            }
        }
    }
}

// Destructor
Catan::~Catan()
{
    delete instance;
    instance = nullptr;
}
