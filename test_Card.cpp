/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include <gtest/gtest.h>
#include "CardBank.hpp"

TEST(CardBankTest, Generate) {

    game::CardBank::generateCard();

    ASSERT_EQ(game::CardBank::bank.size(),25);

    size_t size = 25;
    int mc = 0; // monopoly card
    int bc = 0; // build roads
    int crc = 0; // choose resource card
    int kc = 0; // knights card
    int bpc = 0; // Bonus points card

    while(size > 0){
        game::Card card = game::CardBank::bank.front();
        game::CardBank::bank.pop();
        size--;
        if(card.type == "Monopoly") mc++;
        if(card.type == "Build Roads") bc++;
        if(card.type == "Choose 2 Reasources") crc++;
        if(card.type == "Knights") kc++;
        if(card.type == "Bonus Point") bpc++;
    }
    ASSERT_EQ(mc , 6);
    ASSERT_EQ(bc , 6);
    ASSERT_EQ(crc , 6);
    ASSERT_EQ(kc , 3);
    ASSERT_EQ(bpc , 4);
}