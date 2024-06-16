/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include "Hextile.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

/**
 * chooseResource and chooseProductivity are the "bank",
 * every hextile is assigned randomly to a resource and productivity
 */

vector<std::string> Hextile::chooseResource = {
    "Wood",
    "Sheep",
    "Wood",
    "Wood",
    "Brick",
    "Brick",
    "Ore",
    "Desert",
    "Wheat",
    "Sheep",
    "Wood",
    "Sheep",
    "Wheat",
    "Sheep",
    "Wheat",
    "Wheat",
    "Ore",
    "Ore",
    "Brick",
};

vector<int> Hextile::chooseProductivity = {
    2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};

// For debugging
int Hextile::serialControl = 0;

/*
 * initialize random seed ensures srand() is called only once,
 * preventing reseeding every time a Hextile object is created.
 */

void initializeRandomSeed()
{
    static bool seedInitialized = false;
    if (!seedInitialized)
    {
        srand(static_cast<unsigned int>(time(0)));
        seedInitialized = true;
    }
}

Hextile::Hextile()
{
    initializeRandomSeed();

    /**
     * Random indices for chooseResource and chooseProductivity are calculated based on the current
     * size of the vectors to avoid out-of-bounds access
     */

    // Random index for resources
    if (!chooseResource.empty())
    {
        int randomResourceIndex = rand() % chooseResource.size();
        this->ResourceType = chooseResource[randomResourceIndex];
        chooseResource.erase(chooseResource.begin() + randomResourceIndex);
    }
    // Random index for productivity
    if (this->ResourceType == "Desert")
    {
        this->productivity = 0;
    }
    else if (!chooseProductivity.empty())
    {
        int randomProductivityIndex = rand() % chooseProductivity.size();
        this->productivity = chooseProductivity[randomProductivityIndex];
        chooseProductivity.erase(chooseProductivity.begin() + randomProductivityIndex);
    }
    this->serial = serialControl++;

    // Set default nullptrs
    this->n = nullptr;
    this->nw = nullptr;
    this->ne = nullptr;
    this->s = nullptr;
    this->sw = nullptr;
    this->se = nullptr;
}
