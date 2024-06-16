/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include "node.hpp"

vector<node *> node::occupiedNodes;

node::node(Hextile *r1, Hextile *r2, Hextile *r3)
    : r1(r1), r2(r2), r3(r3), neighbor(nullptr), equals1(nullptr), equals2(nullptr), owner(nullptr), settlement(nullptr), isOcuppied(false) {}

// Sets a settlement on the node for the given player
void node::setSettlement(player *p)
{
    this->owner = p;
    this->settlement = new Village();
    this->isOcuppied = true;
    occupiedNodes.push_back(this);
}

// Upgrades the settlement on the node to a city.
void node::upgradeSettlement()
{
    delete this->settlement;
    this->settlement = new City();
}

// Returns a string representation of the node, including its hex tiles, owner, settlement status, and occupancy.
std::string node::toString() const
{
    std::ostringstream oss;
    oss << "Node: \n";
    oss << "  1: " << (r1 ? r1->toString() : "None") << "\n";
    oss << "  2: " << (r2 ? r2->toString() : "None") << "\n";
    oss << "  3: " << (r3 ? r3->toString() : "None") << "\n";
    oss << "  Owner: " << (owner ? owner->getName() : "None") << "\n";
    oss << "  Settlement: " << (settlement ? settlement->toString() : "None") << "\n";
    oss << "  Is Occupied: " << (isOcuppied ? "Yes" : "No") << "\n";
    return oss.str();
}

// Checks if the current node is a neighbor of the given node n.
bool node::areNeighbors(node *n)
{
    if (this == n)
    {
        throw std::runtime_error("This is the same node");
    }
    node *copy = this;
    bool flag = false;
    for (int i = 1; i < 6; i++)
    {
        copy = copy->neighbor;
        if (copy == n && (i == 1 || i == 5))
        {
            flag = true;
        }
    }
    if (!flag)
    {
        copy = this->equals1 != nullptr ? this->equals1 : nullptr;
        if (copy)
        {
            for (int i = 1; i < 6; i++)
            {
                copy = copy->neighbor;
                if (copy == n && (i == 1 || i == 5))
                {
                    flag = true;
                }
            }
        }
    }
    if (!flag)
    {
        copy = this->equals2 != nullptr ? this->equals2 : nullptr;
        if (copy)
        {
            for (int i = 1; i < 6; i++)
            {
                copy = copy->neighbor;
                if (copy == n && (i == 1 || i == 5))
                {
                    flag = true;
                }
            }
        }
    }
    if (!flag)
    {
        copy = n->equals1 != nullptr ? n->equals1 : nullptr;
        if (copy)
        {
            for (int i = 1; i < 6; i++)
            {
                copy = copy->neighbor;
                if (copy == this && (i == 1 || i == 5))
                {
                    flag = true;
                }
            }
        }
    }
    if (!flag)
    {
        copy = n->equals2 != nullptr ? n->equals2 : nullptr;
        if (copy)
        {
            for (int i = 1; i < 6; i++)
            {
                copy = copy->neighbor;
                if (copy == this && (i == 1 || i == 5))
                {
                    flag = true;
                }
            }
        }
    }
    return flag;
}

// Returns true if the current node is a neighbor of the given node n.
bool node::getNeighbors(node *n)
{
    if (areNeighbors(n))
        return true;
    return false;
}

// Destructor
node::~node()
{
    delete this->settlement;
}

vector<node *> roadNode::nodes;

roadNode::roadNode() : road(nullptr), owner(nullptr), n1(nullptr), n2(nullptr) {}

// Copy constructor
roadNode::roadNode(const roadNode &other)
{
    if (other.road)
    {
        road = new Road(*other.road);
    }
    else
    {
        road = nullptr;
    }
    owner = other.owner;
    n1 = other.n1;
    n2 = other.n2;
}

// Copy assignment operator.
roadNode &roadNode::operator=(const roadNode &other)
{
    if (this == &other)
        return *this;

    delete road;
    if (other.road)
    {
        road = new Road(*other.road);
    }
    else
    {
        road = nullptr;
    }
    owner = other.owner;
    n1 = other.n1;
    n2 = other.n2;
    return *this;
}

// Sets a road between two nodes (n1 and n2) for the given player
void roadNode::setRoad(player *p, node *n1, node *n2)
{
    // Ensures that some road exists, cannot place road on a road.
    int c = 0;
    for (auto &n : nodes)
    {
        if (n == n1)
        {
            c++;
        }
        if (n == n2)
        {
            c++;
        }
    }
    if (c == 2)
    {
        throw std::runtime_error("This edge occupied by another road.");
    }

    this->road = new Road();
    this->owner = p;
    this->n1 = n1;
    this->n2 = n2;
    nodes.push_back(n1);
    nodes.push_back(n2);
}

// Returns the road associated with the road node.
Road *roadNode::getRoad()
{
    return this->road;
}

// Destructor
roadNode::~roadNode()
{
    delete road;
}
