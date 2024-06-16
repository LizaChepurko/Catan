/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#ifndef NODE_HPP
#define NODE_HPP

#include "Settlement.hpp"
#include "Hextile.hpp"
#include "player.hpp"


class player;
class Hextile; 
class Settlement;
class Village;
class City;
class Road;

/**
 * The node class represents a node on the game board in the Catan game. 
 * It contains information about neighboring nodes, equal node, connected roads, settlements, and ownership.
*/
class node {

private:
    bool areNeighbors(node* n);
public:
    static std::vector<node*> occupiedNodes;
    //Pointers to the three hexagonal tiles surrounding the node.
    Hextile* r1;
    Hextile* r2;
    Hextile* r3;
    //Pointer to the neighboring node clock wise
    node* neighbor;
    //Pointers to nodes that share the same hexagonal tiles.
    node* equals1;
    node* equals2;
    //Pointer to the player who owns the node
    player* owner;
    //Pointer to the settlement built on the node.
    Settlement* settlement; 
    //Flag indicating whether the node is occupied by a settlement.
    bool isOcuppied;

    node();
    node(Hextile* r1, Hextile* r2, Hextile* r3);
    bool getNeighbors(node* n);
    void setSettlement(player*);
    void upgradeSettlement();
    std::string toString() const;
    ~node();
};

class roadNode{

    Road* road;
    player* owner;
    static vector<node*> nodes;

public:
    roadNode();
    roadNode(const roadNode& other);
    roadNode& operator=(const roadNode& other);
    node* n1;
    node* n2;
    void setRoad(player* p, node* n1, node* n2);
    Road* getRoad(); // For tests
    ~roadNode();
};

#endif // NODE_HPP
