/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include <gtest/gtest.h>
#include "player.hpp"
#include "Board.hpp"


TEST(PlayerTest, placeSettelemnt_Road_Upgrade) {
    player p1,p2;
    Board board;
    p1.placeSettelemnt(board.block[10].n);

    // Too close to the other village 
    EXPECT_THROW({
        p1.placeSettelemnt(board.block[11].nw);
    }, std::runtime_error);
    
    p1.placeSettelemnt(board.block[15].s);

    // Too close to the other player's village 
    EXPECT_THROW({
        p2.placeSettelemnt(board.block[15].sw);
    }, std::runtime_error);

    // Road not connected to settlemnt
    EXPECT_THROW({
        p1.placeRoad(board.block[0].n, board.block[0].nw);
    }, std::runtime_error);

    // Blocks are not nearby
    EXPECT_THROW({
        p1.placeRoad(board.block[15].s, board.block[0].nw);
    }, std::runtime_error);
    
    // road connected to village in block 10 n
    ASSERT_NO_THROW(p1.placeRoad(board.block[10].n, board.block[6].nw)); 

    p1.placeSettelemnt(board.block[12].n);
    p1.placeRoad(board.block[12].n, board.block[7].s);

    EXPECT_THROW({
        p1.placeRoad(board.block[12].n, board.block[7].s); // Cannot place road on an existing path
    }, std::runtime_error);

    ASSERT_NO_THROW(p1.placeRoad(board.block[7].s, board.block[7].sw)); // road connected to another road
    ASSERT_TRUE(p1.getResources().size()>1);
    ASSERT_EQ(p1.getPoints(),3); // p1 placed 3 villages

    p1.getResources().push_back("Wheat");
    p1.getResources().push_back("Wheat");
    p1.getResources().push_back("Ore");
    p1.getResources().push_back("Ore");
    p1.getResources().push_back("Ore");

    ASSERT_NO_THROW(p1.upgradeVillage(board.block[12].n));
    ASSERT_EQ(p1.getPoints(),4);

    // Not enough resources
    EXPECT_THROW({
        p1.upgradeVillage(board.block[12].n);
    }, std::runtime_error);


    // Not the right block to upgrade
    EXPECT_THROW({
        p1.upgradeVillage(board.block[5].n);
    }, std::runtime_error);

}


TEST(PlayerTest, BuyDevelopmentCard) {
    player p1;
    p1.getResources().push_back("Wheat");
    p1.getResources().push_back("Sheep");
    p1.getResources().push_back("Ore");

    // Assuming CardBank is properly initialized
    game::CardBank::generateCard();

    ASSERT_NO_THROW(p1.buyDevelopmentCard());

    // Not enough resources
    EXPECT_THROW({
        p1.buyDevelopmentCard();
    }, std::runtime_error);

}

TEST(PlayerTest, trade) {
    player p1;
    player p2;
    player p3;
    p1.getResources().push_back("Sheep");
    p1.getResources().push_back("Sheep");
    p2.getResources().push_back("Ore");

    EXPECT_THROW({
        p2.trade(p1,"Ore","Sheep",1,10,true);
    }, std::runtime_error);

    ASSERT_NO_THROW(p2.trade(p1,"Ore","Sheep",1,2,true));
    ASSERT_EQ(p1.getResources().size(), 1); // p1 has ore
    ASSERT_EQ(p2.getResources().size(), 2); // p2 has 2 sheep

    EXPECT_THROW({
        p3.trade(p2,"Brick","Sheep",1,2,true);
    }, std::runtime_error);

}



