/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#ifndef CARD_HPP
#define CARD_HPP

#include <string>

using namespace std;

/**
 * The Card class is an abstract base class representing a generic card in the game.
 * It provides a common interface for all types of cards.
 */

namespace game
{

    class Card
    {

    public:
        std::string price[3] = {"Sheep", "Ore", "Wheat"};
        std::string type;

        virtual ~Card() = default;

        virtual std::string toString() const
        {
            return type;
        }
    };

    class MonopolyCard : public Card
    {

    public:
        MonopolyCard()
        {
            type = "Monopoly";
        }
    };

    class BuildRoads : public Card
    {

    public:
        BuildRoads()
        {
            type = "Build Roads";
        }
    };

    class ChooseReasources : public Card
    {

    public:
        ChooseReasources()
        {
            type = "Choose 2 Reasources";
        }
    };

    class Knights : public Card
    {

    public:
        Knights()
        {
            type = "Knights";
        }
    };

    class BiggestArmy : public Card
    {

    public:
        BiggestArmy()
        {
            type = "Biggest Army";
        }
    };

    class BonusPoints : public Card
    {

    public:
        BonusPoints()
        {
            type = "Bonus Point";
        }
    };
}

#endif