#ifndef WEAPON_H
#define WEAPON_H
#include <global.h>
#include "Element.h"

/**
 * @class Weapon
 * @brief Base class for weapon (fire or harpoon) logic
 * @author Benji
 * @date 23/09/2016
 * @file Weapon.h
 */

class Weapon : public Element
{
public:
    /**
     * @brief Inintialises the weapon to not be shooting
     */
    Weapon();

    /**
     * @brief get x,y co-ords of positions that are occupied by the weapon
     * @return a vector of x,y co-ords of positions occupied
     */
    std::vector<sf::Vector2f> getOccupiedBlocks();

    /**
     * @brief Pure virtual function. Sets in motion logic when the weapon has been shot
     * @param pos x,y co-ords of the entity shooting the weapon (Dragon or Dug)
     * @param direction Direction in which entity is facing
     */
    virtual void shoot(const sf::Vector2f& pos, const Direction& direction) = 0;

protected:
    Direction _direction;
    std::vector<sf::Vector2f> _squaresOccupied;
};

#endif