/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#ifndef HEXTILE_HPP
#define HEXTILE_HPP

#include <vector>
#include <iostream>
#include "node.hpp"
#include "player.hpp"
#include <string>

using namespace std;

class node;

/**
 * The Hextile class represents a hexagonal tile on the game board in the Catan game.
 * It contains information about the type of resource, productivity, and serial number of the tile.
 */

class Hextile
{

private:
    static vector<std::string> chooseResource;
    static vector<int> chooseProductivity;
    static int serialControl;

public:
    int serial;
    int productivity;
    std::string ResourceType;
    /**
    node s*: Pointer to the south node of the hextile.
    node sw*: Pointer to the southwest node of the hextile.
    node se*: Pointer to the southeast node of the hextile.
    node nw*: Pointer to the northwest node of the hextile.
    node ne*: Pointer to the northeast node of the hextile.
    node n*: Pointer to the north node of the hextile.
    */
    node *s;
    node *sw;
    node *se;
    node *nw;
    node *ne;
    node *n;

    Hextile();
    std::string toString() const
    {
        return "Hextile: " + ResourceType + ", Productivity: " + std::to_string(productivity) + ", Serial: " + std::to_string(serial);
    }
};

#endif
