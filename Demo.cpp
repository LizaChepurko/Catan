/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include <iostream>
#include "Board.hpp"
#include "player.hpp"
#include "Settlement.hpp"
#include "Catan.hpp"
#include <thread>
#include "Utils.hpp"


using namespace game;
using namespace std;

int main(){

    player p1("Amit");
    player p2("Yossi");
    player p3("Dana");

    /**
     * Initialize the board and create all of the blocks and cards
    */
    cout<<"The resulting random map: \n"<<endl;

    Catan& catan = Catan::getInstance();
    catan.initialize(p1, p2, p3);
    Board board = catan.getBoard();
    game::CardBank::generateCard();
   

    // Load font
    sf::Font font;
    if (!font.loadFromFile("JetBrainsMono-SemiBold.ttf")) {
        return -1;
    }

    std::thread sfmlThread(runSfmlWindow, std::ref(board), std::ref(font));

    cout<<endl;
    /**
     * Demo to place first settelment.
    */
    cout << "===================================================================" << endl;
    cout << "Demo 1 - Simulates: \n * A block initial selection and placing settlements \n * Dice roll" << endl;
    cout << "-------------------------------------------------------------------\n" << endl;

    p1.placeSettelemnt(board.block[9].n);
    p1.placeRoad(board.block[9].n, board.block[5].nw);
    p2.placeSettelemnt(board.block[0].sw);
    p2.placeRoad(board.block[0].sw, board.block[3].ne);
    p3.placeSettelemnt(board.block[13].se);

    // Simulates a location selection error
    try {
        p3.placeRoad(board.block[13].se, board.block[1].ne);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    p3.placeRoad(board.block[13].se, board.block[17].ne);

    // Cannot place road on an existing path
    try {
        p3.placeRoad(board.block[13].se, board.block[17].ne);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    p1.placeSettelemnt(board.block[12].n);
    p1.placeRoad(board.block[12].n, board.block[7].s);
    p2.placeSettelemnt(board.block[11].sw);
    p2.placeRoad(board.block[11].sw, board.block[15].nw);
    p3.placeSettelemnt(board.block[1].ne);
    p3.placeRoad(board.block[1].ne, board.block[2].n);

    p1.rollDice();

    cout << "===================================================================" << endl;
    cout << "Demo 2 - Simulates: \n * Buying development card" << endl;
    cout << "-------------------------------------------------------------------\n" << endl;

    /**
     * In the real game every player getting resource according to the result of the dice.
     * But for illustrate other methodes of player I put the resources in a controlled manner.
    */
    p1.getResources().push_back("Wheat");
    p1.getResources().push_back("Ore");
    p1.getResources().push_back("Sheep");
    p2.getResources().push_back("Brick");
    p2.getResources().push_back("Ore");
    p2.getResources().push_back("Wheat");
    p2.getResources().push_back("Sheep");
    p3.getResources().push_back("Wood");
    p3.getResources().push_back("Wheat");
    p3.getResources().push_back("Ore");
    
    try {
        p1.buyDevelopmentCard();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    cout << "===================================================================" << endl;
    cout << "Demo 3 - Simulates: \n * Trading" << endl;
    cout << "-------------------------------------------------------------------\n" << endl;

    p1.getResources().push_back("Ore");
    p3.getResources().push_back("Wheat");

    try{
        p1.trade(p3,"Ore","Wheat",1,1,true); //try to enter 10 instead of 1 to ensure an error
    } catch (const std::runtime_error& e) {
         std::cerr << e.what() << std::endl;
    }

    cout << "===================================================================" << endl;
    cout << "Demo 4 - Simulates: \n * Upgrading village" << endl;
    cout << "-------------------------------------------------------------------\n" << endl;

    p2.getResources().push_back("Wheat");
    p2.getResources().push_back("Wheat");
    p2.getResources().push_back("Ore");
    p2.getResources().push_back("Ore");
    p2.getResources().push_back("Ore");

    try{
        p2.upgradeVillage(board.block[11].sw);
    } catch (const std::runtime_error& e) {
         std::cerr << e.what() << std::endl;
    }


    cout << "===================================================================" << endl;
    cout << "Demo 5 - Simulates: \n * Adding road \n * Attach village to the road \n * Printing current points" << endl;
    cout << "-------------------------------------------------------------------\n" << endl;

    p3.getResources().push_back("Brick");
    p3.getResources().push_back("Wood");
    p3.getResources().push_back("Brick");
    p3.getResources().push_back("Wood");
    p3.getResources().push_back("Sheep");
    p3.getResources().push_back("Wheat");

    try{
        p3.placeRoad(board.block[17].ne,board.block[17].se);
    } catch (const std::runtime_error& e) {
         std::cerr << e.what() << std::endl;
    }

    try{
        p3.placeSettelemnt(board.block[17].se); // must conncet the settlement to the end of one of your roads 
    } catch (const std::runtime_error& e) {
         std::cerr << e.what() << std::endl;
    }
    
    p1.printPoints();
    p2.printPoints();
    p3.printPoints();

    sfmlThread.join();

    return 0;
}