/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#ifndef CARDBANK_HPP
#define CARDBANK_HPP

#include "Card.hpp"
#include <queue>
#include <iostream>

/**
 * A factory class
 * The CardBank class manages a bank of cards in the game.
 * It is responsible for generating a predefined set of cards and making them available for the game.
 * The CardBank includes various card types such as MonopolyCard, BuildRoads, ChooseReasources, Knights, BiggestArmy, and BonusPoints.
 */
namespace game
{

    class CardBank
    {

    public:
        static queue<Card> bank;
        static BiggestArmy BiggestArmyCard;
        // prints ensures that the cards order generated randomly, check it also in test_Card.cpp
        static void generateCard()
        {
            int knights = 0;
            int points = 0;
            int chooseReasource = 0;
            int buildRoad = 0;
            int bank_size = 0;
            int monopoly = 0;
            while (bank_size < 25)
            {
                int c = (rand() % 5) + 1;
                if (c == 1)
                {
                    if (monopoly < 6)
                    {
                        MonopolyCard m;
                        bank.push(m);
                        monopoly++;
                        // cout<<"monopoly "<<monopoly<<endl;
                        bank_size++;
                    }
                }
                else if (c == 2)
                {
                    if (buildRoad < 6)
                    {
                        BuildRoads b;
                        bank.push(b);
                        buildRoad++;
                        // cout<<"build roads "<<buildRoad<<endl;
                        bank_size++;
                    }
                }
                else if (c == 3)
                {
                    if (chooseReasource < 6)
                    {
                        ChooseReasources c;
                        bank.push(c);
                        chooseReasource++;
                        // cout<<"choose resource "<<chooseReasource<<endl;
                        bank_size++;
                    }
                }
                else if (c == 4)
                {
                    if (knights < 3)
                    {
                        Knights k;
                        bank.push(k);
                        knights++;
                        // cout<<"knights "<<knights<<endl;
                        bank_size++;
                    }
                }
                else if (c == 5)
                {
                    if (points < 4)
                    {
                        BonusPoints bp;
                        bank.push(bp);
                        points++;
                        // cout<<"bonus points "<<points<<endl;
                        bank_size++;
                    }
                }
            }
        }
    };

}

#endif