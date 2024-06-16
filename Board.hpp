/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Hextile.hpp"
#include <vector>

/**
 * The Board class represents the game board for the Catan game, 
 * creating hextiles and managing their interactions.
 * Provides a way to accessing specific blocks.
 * 
*/
class Board
{
private:
    void setRelatedBlocks();
public:
    // Static vector holding all hextiles on the board. 
    static vector<Hextile> block;
    Board();
    // Initializes the board and sets up the hextiles.
    void init();
    ~Board();
    Hextile setSettlement(node dir);

};

#endif




