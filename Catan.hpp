/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#ifndef CATAN_HPP
#define CATAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Board.hpp"
#include "CardBank.hpp"
#include "player.hpp"

class Board;

/**
 * The Catan class manages the core logic and state of the Catan game.
 * It follows the singleton design pattern to ensure that only one instance of the game exists.
 * The class manages players and the game board.
 */

class Catan
{
private:
    static Catan *instance;
    player p1;
    player p2;
    player p3;
    ~Catan();

public:
    // This static method provides access to the singleton instance of the Catan class.
    // If the instance does not exist, it creates a new one.
    static Catan &getInstance()
    {
        if (!instance)
        {
            instance = new Catan();
        }
        return *instance;
    }
    // The initialize method initializes the game with three player instances.
    void initialize(player &p1, player &p2, player &p3);
    // The ChooseStartingPlayer method selects the starting player for the game based on random selection.
    void ChooseStartingPlayer();
    Board getBoard();
    void printwinner();
};

#endif // CATAN_HPP
