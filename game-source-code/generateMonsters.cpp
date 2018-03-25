#include <vector>
#include "Dragon.h"
#include "Monster.h"

void generateMonsters(std::vector<Monster>& monstVec, std::vector<Dragon>& dragonVec)
{
    monstVec.resize(4);
    monstVec[0].setStartPosition(sf::Vector2f(15, 10));
    monstVec[1].setStartPosition(sf::Vector2f(40, 15));
    monstVec[2].setStartPosition(sf::Vector2f(27, 14));
    monstVec[3].setStartPosition(sf::Vector2f(52, 5));

    dragonVec.resize(3);
    dragonVec[0].setStartPosition(sf::Vector2f(40, 18));
    dragonVec[1].setStartPosition(sf::Vector2f(11, 0));
    dragonVec[2].setStartPosition(sf::Vector2f(40, 9));
}