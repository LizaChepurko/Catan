/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include "player.hpp"

vector<player *> player::players;
bool player::game_started = false;

player::player()
{
}

player::player(string name)
{
    this->name = name;
    players.push_back(this);
}
// Places a village on a node
void player::placeSettelemnt(node *n)
{
    if (n->isOcuppied)
    { // Check if the node is already occupied
        throw std::runtime_error("This block is occupied.");
    }
    // Checks if the distance from other settelemnt is more then one road.
    for (size_t i = 0; i < n->occupiedNodes.size(); i++)
    {
        if (n->occupiedNodes[i]->getNeighbors(n))
        {
            throw std::runtime_error("Distance between two settlements must be more then one road.");
        }
    }

    if (this->turn < 4)
    {
        // Ensures every resource is received one time
        n->setSettlement(this);
        this->points++;
        cout << this->getName() << " placed village" << endl;

        // Helper lambda function to add resource if not already present
        auto addResourceOnce = [this](const string &resourceType)
        {
            if (!resourceType.empty() && resourceType != "Desert")
            {
                if (find(this->resources.begin(), this->resources.end(), resourceType) == this->resources.end())
                {
                    this->resources.push_back(resourceType);
                    cout << this->getName() << " received " << resourceType << endl;
                }
            }
        };

        if (n->r1)
            addResourceOnce(n->r1->ResourceType);
        if (n->r2)
            addResourceOnce(n->r2->ResourceType);
        if (n->r3)
            addResourceOnce(n->r3->ResourceType);

        // checks if the settlemnt connected to a road
    }
    else if (turn >= 4)
    {
        if (!checkConnectedRoad(n))
        {
            throw std::runtime_error("Settlment must be connected to a road");
        }
        // uses the resources for building village, holding exceptions.
        if (buildVillage())
        {
            n->setSettlement(this);
            cout << this->getName() << " placed a village" << endl;
        }
    }
    this->turn++;
    this->nodes.push_back(n);
}

// upgrates villages to cities
void player::upgradeVillage(node *n)
{
    if (!n->isOcuppied || n->owner != this)
    {
        throw std::runtime_error("This node isn't contains any of yours settlements");
    }
    // Uses resources to build a city holding exceptions.
    if (buildCity())
    {
        n->upgradeSettlement();
        cout << this->getName() << " Upgradet to city successfully." << endl;
    }
    turn++;
}

/**
 * Settlemnt should be connectd to a road after the first 4 turns
 */
bool player::checkConnectedRoad(node *n)
{
    for (size_t i = 0; i < roads.size(); i++)
    {
        if (roads[i].n2 == n)
        {
            return true;
        }
    }

    return false;
}

/**
 * This method ensures that roads are placed according to the game rules,
 * considering node connections, turn-based restrictions, and resource availability.
 */

void player::placeRoad(node *n1, node *n2)
{
    if (n1 == n2)
        throw std::runtime_error("This node is taken");
    if (n1->getNeighbors(n2) == false)
        throw std::runtime_error("The blocks you chose are not nearby");
    /**
     * If there are already roads built in the game (roads.size() > 1), it iterates through the existing roads
     * to ensure that the new road connects to an existing settlement or another road.
     * If the road doesn't connect, it throws an error.
     */
    if (roads.size() > 1)
    {
        size_t i = 0;
        for (; i < this->roads.size(); i++)
        {
            if ((this->roads[i].n1 != nullptr && this->roads[i].n1 == n1) || (this->roads[i].n2 != nullptr && this->roads[i].n2 == n2) || (this->roads[i].n2 != nullptr && this->roads[i].n2 == n1) || (this->roads[i].n1 != nullptr && this->roads[i].n1 == n2))
            {
                break;
            }
        }
        if (i == this->roads.size())
        {
            throw std::runtime_error("Road must be connected to a settlement or to another road");
        }
    }
    /**
     * If the current turn is less than 4, it ensures that the road is connected to the player's settlement.
     * If not, it throws an error indicating that the road must be connected to the player's settlement.
     */
    if (this->turn < 4)
    {
        if ((n1->owner == nullptr || n1->owner != this) && (n2->owner == nullptr || n2->owner != this))
        {
            throw std::runtime_error("You must connect the road to your settlement");
        }
    }

    /**
     * If the current turn is beyond the initial setup phase (greater than 4),
     * it calls the buildRoad method to check if the player has the necessary resources to build a road.
     * If they do, it creates a new roadNode and adds it to the player's list of roads.
     */
    if (this->turn > 4)
    {
        if (buildRoad())
        {
            roadNode r;
            r.setRoad(this, n1, n2);
            this->roads.push_back(r);
        }
    }
    else
    {
        roadNode r;
        r.setRoad(this, n1, n2);
        this->roads.push_back(r);
    }
    this->turn++;
    cout << this->getName() << " placed road successfully." << endl;
}

/**
 * This method simulates rolling two dice and calculates their sum.
 * Then, it calls the notify method, which acts as an observer to inform
 * each player about the result of the dice roll and distribute resources accordingly.
 */

int player::rollDice()
{
    int dice_res1 = (rand() % 6) + 1;
    int dice_res2 = (rand() % 6) + 1;
    int total = dice_res1 + dice_res2;
    cout << "Dies roll: " << total << endl;
    notify(total);
    return total;
}

/**
For each player, it iterates over the nodes they own (nodes).
For each node, it checks if any of its resources' productivity matches the total dice roll.
If a match is found, the corresponding resource type is added to the player's resources.
If the player's settlement at that node has been upgraded to a city (points equal to 2), the resource is added twice.
A message is printed to the console indicating the player's receipt of resources from the dice roll.
*/
void player::notify(int total)
{
    for (size_t i = 0; i < players.size(); i++)
    {
        // If dice result is 7
        if (total == 7 && players[i]->resources.size() > 7)
        {
            int s = resources.size();
            players[i]->resources.erase(players[i]->resources.begin() + players[i]->resources.size() / 2 - 1);
            cout << players[i]->getName() << " returned " << s / 2 << " resources to bank" << endl;
        }
        for (size_t j = 0; j < players[i]->nodes.size(); j++)
        {
            if ((players[i]->nodes[j]->r1 != nullptr) && (players[i]->nodes[j]->r1->productivity == total))
            {
                players[i]->resources.push_back(players[i]->nodes[j]->r1->ResourceType);
                if (players[i]->nodes[j]->settlement->points == 2)
                {
                    players[i]->resources.push_back(players[i]->nodes[j]->r1->ResourceType);
                    cout << players[i]->getName() << " recieved: " << players[i]->nodes[j]->r1->ResourceType << " from dice roll" << endl;
                }
                cout << players[i]->getName() << " recieved: " << players[i]->nodes[j]->r1->ResourceType << " from dice roll" << endl;
            }
            if ((players[i]->nodes[j]->r2 != nullptr) && (players[i]->nodes[j]->r2->productivity == total))
            {
                players[i]->resources.push_back(players[i]->nodes[j]->r2->ResourceType);
                if (players[i]->nodes[j]->settlement->points == 2)
                {
                    players[i]->resources.push_back(players[i]->nodes[j]->r2->ResourceType);
                    cout << players[i]->getName() << " recieved: " << players[i]->nodes[j]->r2->ResourceType << " from dice roll" << endl;
                }
                cout << players[i]->getName() << " recieved: " << players[i]->nodes[j]->r2->ResourceType << " from dice roll" << endl;
            }
            if ((players[i]->nodes[j]->r3 != nullptr) && (players[i]->nodes[j]->r3->productivity == total))
            {
                players[i]->resources.push_back(players[i]->nodes[j]->r3->ResourceType);
                if (players[i]->nodes[j]->settlement->points == 2)
                {
                    players[i]->resources.push_back(players[i]->nodes[j]->r3->ResourceType);
                    cout << players[i]->getName() << " recieved: " << players[i]->nodes[j]->r3->ResourceType << " from dice roll" << endl;
                }
                cout << players[i]->getName() << " recieved: " << players[i]->nodes[j]->r3->ResourceType << " from dice roll" << endl;
            }
        }
    }
}

/**
 * First It counts how many of the desired resources (mysource and wantedsource) each player (this and p2) possesses.
 * If either player doesn't have enough of the specified resource to trade, it throws an exception.
 * If p2_decision is true, indicating that the second player (p2) agrees to the trade:
 * It iterates over p2's resources and removes wanteditem occurrences of wantedsource.
 * It iterates over this player's resources and removes myitem occurrences of mysource.
 * It adds myitem copies of mysource to p2's resources and wanteditem copies of wantedsource to this player's resources.
 */

void player::trade(player &p2, const string &mysource, const string &wantedsource, int myitem, int wanteditem, bool p2_decision)
{

    int c1 = 0, c2 = 0;

    for (const auto &res : resources)
    {
        if (res == mysource)
        {
            c1++;
        }
    }
    if (c1 < myitem)
        throw std::runtime_error("You don't have enough of this item to trade!");

    for (const auto &res : p2.resources)
    {
        if (res == wantedsource)
        {
            c2++;
        }
    }
    if (c2 < wanteditem)
        throw std::runtime_error("The player doesn't have enough of this item to trade!");

    if (p2_decision)
    {
        c1 = 0, c2 = 0;

        /**
         * After erasing an element, the iterator is updated to point to the next valid element,
         * preventing issues caused by invalidated indices.
         */
        for (auto it = p2.resources.begin(); it != p2.resources.end();)
        {
            if (*it == wantedsource && c2 < wanteditem)
            {
                it = p2.resources.erase(it);
                c2++;
            }
            else
            {
                ++it;
            }
        }

        for (auto it = resources.begin(); it != resources.end();)
        {
            if (*it == mysource && c1 < myitem)
            {
                it = resources.erase(it);
                c1++;
            }
            else
            {
                ++it;
            }
        }

        for (int i = 0; i < myitem; i++)
        {
            p2.resources.push_back(mysource);
        }
        for (int i = 0; i < wanteditem; i++)
        {
            resources.push_back(wantedsource);
        }
    }

    cout << this->getName() << " traded " << myitem << " " << mysource << " for " << wanteditem << " " << wantedsource << " with " << p2.getName() << endl;
    this->turn++;
}

/**
 * Checks if the player has enough resources (wheat, sheep, and ore) to buy a development card.
 * If the player has the required resources, it removes them from the player's resources.
 * Draws a card from the card bank, adds it to the player's card collection, and updates the player's points or performs other actions based on the drawn card's type.
 */

void player::buyDevelopmentCard()
{
    int ore = 0;
    int sheep = 0;
    int wheat = 0;
    for (size_t i = 0; i < this->resources.size(); i++)
    {
        if (this->resources[i] == "Wheat")
        {
            wheat++;
        }
        if (this->resources[i] == "Sheep")
        {
            sheep++;
        }
        if (this->resources[i] == "Ore")
        {
            ore++;
        }
    }
    if (wheat < 1)
    {
        throw std::runtime_error("You don't have enough wheat to buy development card.");
    }
    if (sheep < 1)
    {
        throw std::runtime_error("You don't have enough sheep to buy development card.");
    }
    if (ore < 1)
    {
        throw std::runtime_error("You don't have enough ore to buy development card.");
    }
    wheat = 0;
    sheep = 0;
    ore = 0;
    size_t i = 0;
    while (i < this->resources.size())
    {
        if (this->resources[i] == "Wheat" && wheat == 0)
        {
            this->resources.erase(this->resources.begin() + i);
            wheat++;
        }
        else if (this->resources[i] == "Sheep" && sheep == 0)
        {
            this->resources.erase(this->resources.begin() + i);
            sheep++;
        }
        else if (this->resources[i] == "Ore" && ore == 0)
        {
            this->resources.erase(this->resources.begin() + i);
            ore++;
        }
        else
        {
            i++;
        }
        if (wheat == 1 && sheep == 1 && ore == 1)
        {
            break;
        }
    }
    game::Card card = game::CardBank::bank.front();
    game::CardBank::bank.pop();
    cards.push_back(card);
    cout << this->getName() << " received " << card.toString() << endl;
    if (card.toString() == "Bonus Point")
    {
        this->points++;
    }

    else if (card.toString() == "Knights")
    {
        this->knights++;
        if (this->knights == 3)
        {
            this->points = this->points + 2;
            this->cards.push_back(game::CardBank::BiggestArmyCard);
            cout << this->getName() << " has the biggest army now" << endl;
        }
    }
    else if (card.toString() == "Build Roads")
    {
        this->can_build_free_road = true;
    }
    else if (card.toString() == "Choose 2 Reasources")
    {
        Choose_Reasource();
    }
    else if (card.toString() == "Monopoly")
    {
        StealReasource();
    }

    cards.clear(); // Cannot use card again
}

/**
    Allows the player to choose two random resources from the bank.
    It randomly selects a resource type (wood, brick, wheat, ore, or sheep)
    and adds it to the player's resources, repeating this process twice.
*/
void player::Choose_Reasource()
{
    int n = 0;
    int r = (rand() % 5) + 1;
    while (n < 2)
    {
        if (r == 1)
        {
            this->resources.push_back("Wood");
            cout << this->getName() << " took Wood from bank" << endl;
            n++;
        }
        if (r == 2)
        {
            this->resources.push_back("Brick");
            cout << this->getName() << " took Brick from bank" << endl;
            n++;
        }
        if (r == 3)
        {
            this->resources.push_back("Wheat");
            cout << this->getName() << " took Wheat from bank" << endl;
            n++;
        }
        if (r == 4)
        {
            this->resources.push_back("Ore");
            cout << this->getName() << " took ore from bank" << endl;
            n++;
        }
        if (r == 5)
        {
            this->resources.push_back("Sheep");
            cout << this->getName() << " took sheep from bank" << endl;
            n++;
        }
    }
}

/**
    Randomly selects a resource type from wood, brick, wheat, ore, or sheep.
    Iterates through other players' resources to find the chosen resource type and steals it.
    Adds the stolen resource to the player's resources.
*/
void player::StealReasource()
{
    string res;
    int r = (rand() % 5) + 1;
    if (r == 1)
    {
        res = "Wood";
    }
    if (r == 2)
    {
        res = "Brick";
    }
    if (r == 3)
    {
        res = "Wheat";
    }
    if (r == 4)
    {
        res = "Ore";
    }
    if (r == 5)
    {
        res = "Sheep";
    }

    for (size_t i = 0; i < players.size(); i++)
    {
        if (players[i] != this)
        {
            for (size_t j = 0; j < players[i]->resources.size(); j++)
            {
                if (players[i]->resources[j] == res)
                {
                    players[i]->resources.erase(players[i]->resources.begin() + j);
                    cout << this->getName() << " took " << res << " from " << players[i]->getName() << endl;
                    this->resources.push_back(res);
                    break;
                }
            }
        }
    }
}

/**
 * Checks if the player has enough resources (wheat, sheep, wood, and brick) to build a village.
    If the player has the required resources, it removes them from the player's resources.
    Increases the player's points by one.
    Returns true if the village is successfully built.
*/

bool player::buildVillage()
{

    int wheat = 0;
    int sheep = 0;
    int wood = 0;
    int brick = 0;
    for (size_t i = 0; i < this->resources.size(); i++)
    {
        if (this->resources[i] == "Wheat")
        {
            wheat++;
        }
        if (this->resources[i] == "Sheep")
        {
            sheep++;
        }
        if (this->resources[i] == "Wood")
        {
            wood++;
        }
        if (this->resources[i] == "Brick")
        {
            brick++;
        }
    }
    if (wheat < 1)
    {
        throw std::runtime_error("You don't have enough wheat to build village.");
        return false;
    }
    if (sheep < 1)
    {
        throw std::runtime_error("You don't have enough sheep to build village.");
        return false;
    }
    if (wood < 1)
    {
        throw std::runtime_error("You don't have enough wood to build village.");
        return false;
    }
    if (brick < 1)
    {
        throw std::runtime_error("You don't have enough brick to build village.");
        return false;
    }

    wheat = 0;
    sheep = 0;
    wood = 0;
    brick = 0;
    size_t i = 0;
    while (i < this->resources.size())
    {
        if (this->resources[i] == "Wheat" && wheat == 0)
        {
            this->resources.erase(this->resources.begin() + i);
            wheat++;
        }
        else if (this->resources[i] == "Sheep" && sheep == 0)
        {
            this->resources.erase(this->resources.begin() + i);
            sheep++;
        }
        else if (this->resources[i] == "Wood" && wood == 0)
        {
            this->resources.erase(this->resources.begin() + i);
            wood++;
        }
        else if (this->resources[i] == "Brick" && brick == 0)
        {
            this->resources.erase(this->resources.begin() + i);
            brick++;
        }
        else
        {
            i++; // Increment i only if we do not erase the current element
        }
        if (wheat == 1 && sheep == 1 && wood == 1 && brick == 1)
        {
            break;
        }
    }
    this->points++;
    return true;
}
/**
 * Checks if the player has enough resources (wheat and ore) to upgrade a village to a city.
    If the player has the required resources, it removes them from the player's resources.
    Increases the player's points by one.
    Returns true if the city is successfully built.
*/
bool player::buildCity()
{
    int wheat = 0;
    int ore = 0;
    for (size_t i = 0; i < this->resources.size(); i++)
    {
        if (this->resources[i] == "Wheat")
        {
            wheat++;
        }
        if (this->resources[i] == "Ore")
        {
            ore++;
        }
    }
    if (ore < 3)
    {
        throw std::runtime_error("You don't have enough ore to upgrade this village.");
        return false;
    }
    if (wheat < 2)
    {
        throw std::runtime_error("You don't have enough wheat to upgrade this village.");
        return false;
    }
    // Remove resources
    wheat = 0;
    ore = 0;
    size_t i = 0;
    while (i < this->resources.size())
    {
        if (this->resources[i] == "Wheat" && wheat < 2)
        {
            this->resources.erase(this->resources.begin() + i);
            wheat++;
        }
        else if (this->resources[i] == "Ore" && ore < 3)
        {
            this->resources.erase(this->resources.begin() + i);
            ore++;
        }
        else
        {
            i++;
        }
        if (wheat == 2 && ore == 3)
        {
            break;
        }
    }
    this->points++;
    return true;
}

/**
 * Checks if the player can build a road for free (due to a development card)
    or if they have enough resources (brick and wood) to build a road.
    If the player has enough resources, it removes them from the player's resources.
    Returns true if the road is successfully built.
*/
bool player::buildRoad()
{
    if (this->can_build_free_road)
    {
        this->free_road++;
        if (this->free_road == 2)
        {
            this->can_build_free_road = false;
            this->free_road = false;
        }
        return true;
    }
    int brick = 0;
    int wood = 0;
    for (size_t i = 0; i < this->resources.size(); i++)
    {
        if (this->resources[i] == "Wood")
        {
            wood++;
        }
        if (this->resources[i] == "Brick")
        {
            brick++;
        }
    }
    if (wood < 1)
    {
        throw std::runtime_error("You don't have enough wood build a road.");
        return false;
    }
    if (brick < 1)
    {
        throw std::runtime_error("You don't have enough brick build a road.");
        return false;
    }
    // Remove resources
    brick = 0;
    wood = 0;
    size_t i = 0;
    while (i < this->resources.size())
    {
        if (this->resources[i] == "Brick" && brick == 0)
        {
            this->resources.erase(this->resources.begin() + i);
            brick++;
        }
        else if (this->resources[i] == "Wood" && wood == 0)
        {
            this->resources.erase(this->resources.begin() + i);
            wood++;
        }
        else
        {
            i++;
        }
        if (brick == 1 && wood == 1)
        {
            break;
        }
    }
    return true;
}

vector<roadNode> &player::getRoads()
{
    return this->roads;
}

vector<string> &player::getResources()
{
    return this->resources;
}

void player::printPoints()
{
    cout << this->getName() << " has " << this->points << " points" << endl;
}

int player::getPoints()
{
    return this->points;
}

string player::getName()
{
    return this->name;
}

// Adding a function to clear player resources
void player::clearResources()
{
    for (auto *n : nodes)
    {
        delete n;
    }
    nodes.clear();
    roads.clear();
}

// Method to clean up all players
void player::cleanupPlayers()
{
    players.clear();
}