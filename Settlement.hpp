/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP


#include "node.hpp"
#include <sstream> 

/**
 * The Settlement class is an abstract base class representing a generic settlement in the game. 
 * It provides a common interface for all types of settlements.
*/
class Settlement{
    public:
        int points;
        std::string type;
        std::string toString() const{
            std::ostringstream oss;
            oss << type;
            return oss.str();
    }
};

class Village : public Settlement
{
private:
    int points = 1;
public:
   
    Village() {
        type = "Village";
    }
};

class City : public Settlement{

private:
    int points = 2;
public:
    City(){
        type = "City";
    }

};

class Road : public Settlement{

private:
    int points = 0;
public:
    Road(){
        type = "Road";
    }

};

#endif // SETTLEMENT_HPP
