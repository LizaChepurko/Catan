/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

using namespace std;



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Settlement.hpp"
#include "Card.hpp"
#include "CardBank.hpp"


class node;
class Settlement;
class roadNode;
class CardBank;
class Catan;



class player
{
private:
    string name;
    int turn = 0;
    int points = 0;
    // A flag indicating if the player can build a free road
    bool can_build_free_road;
    //The number of free roads available to the player.
    int free_road;
    //The number of knights owned by the player.
    int knights;
    //The nodes owned by the player.
    vector<node*> nodes;
    //The cards held by the player.
    vector<game::Card> cards;
    //The roads built by the player.
    vector<roadNode> roads;
    //The resources owned by the player.
    vector<string> resources;
    //Checks if the node is connected to any road.
    bool checkConnectedRoad(node* n);
    //Notifies the player about a dice roll event.
    void notify(int);
    // Allows the player to choose a resource.
    void Choose_Reasource();
    //Steals a resource from another player.
    void StealReasource();
    //Builds a village for the player.
    bool buildVillage();
    //Builds a city for the player.
    bool buildCity();
    //Builds a road for the player.
    bool buildRoad();
    
public:
    //A static flag indicating if the game has started.
    static bool game_started;
    //A static vector containing all players in the game.
    static vector<player*> players;
    player(const string name);
    player();
    //Places a settlement for the player on the given node.
    void placeSettelemnt(node* node);
    //Upgrades the village to a city on the given node.
    void upgradeVillage(node* node);
    //Places a road between two nodes.
    void placeRoad(node* n1, node* n2);
    //Simulates rolling a dice and returns the result.
    int rollDice();
    //Initiates a trade with another player.
    void trade(player &p2, const string &mysource,const string &wantedsource, int myitem, int wanteditem, bool p2_decision);
    //Allows the player to buy a development card.
    void buyDevelopmentCard();
    //Returns a reference to the vector of roads built by the player.
    vector<roadNode>& getRoads();
    //Returns a reference to the vector of resources owned by the player.
    vector<string>& getResources();
    //Returns the total points scored by the player.
    int getPoints();
    //Prints the total points scored by the player.
    void printPoints();
    //Returns the name of the player.
    string getName();
    void clearResources();
    static void cleanupPlayers();

};

#endif


