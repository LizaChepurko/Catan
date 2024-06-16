/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include <gtest/gtest.h>
#include "player.hpp"
#include "node.hpp"
#include "Board.hpp"


TEST(NodeTest, Set_Settlement) {

    player p;
    Board board;
    node* n = board.block[0].ne;
    n->setSettlement(&p);

    ASSERT_TRUE(n->isOcuppied == true);
    ASSERT_TRUE(n->owner == &p);

}

TEST(NodeTest, Get_Neighbors) {

    Board board;
    node* n1 = board.block[0].ne;
    node* n2 = board.block[0].se;
    node* n3 = board.block[0].n;
    node* n4 = board.block[0].sw;
    node* n5 = board.block[3].nw;

    ASSERT_TRUE(n1->getNeighbors(n2));
    ASSERT_TRUE(n1->getNeighbors(n3));
    ASSERT_TRUE(n4->getNeighbors(n5));

    EXPECT_THROW({
        n1->getNeighbors(n1);
    }, std::runtime_error);
    
    ASSERT_FALSE(n1->getNeighbors(n5));
}

TEST(RoadTest, Set_Roads) {

    player p;
    Board board;
    node* n1 = board.block[0].ne;
    node* n2 = board.block[0].se;

    roadNode r;
    r.setRoad(&p,n1,n2);

    ASSERT_TRUE(r.getRoad());

}