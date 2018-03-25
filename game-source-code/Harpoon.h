#ifndef HARPOON_H
#define HARPOON_H
#include "global.h"
#include "Weapon.h"
/**
 * @class Harpoon
 * @brief Manages Harpoon's logic
 * @author Benji
 * @date 22/09/2016
 * @file Harpoon.h
 */

class Harpoon : public Weapon
{
public:
    /**
     * @brief Constructed to be automatically NOT shooting
     */
    Harpoon();

    /**
    * @brief Shoot harpoon. Harpoon is only fired every second call to shoot().
    * @param pos x,y co-ords of Dug which in turn determine x,y co-ords of starting postion of the harpoon
    * @param direction Dug's direction which in turn determines the direction which the Harpoon is facing
    */
    virtual void shoot(const sf::Vector2f& pos, const Direction& direction) override;

    /**
     * @brief Determines if Harpoon is currently being shot
     * @return True if harpoon is currently being fired, false otherwise
     */
    bool isShooting() const;

    /**
     * @brief Set Harpoon to longer be shooting and move its postion to the origin where it will not have unwanted
     * interactions with other elements
     */
    void withdrawHarpoon();

private:
    bool _canShoot;
    bool _isShooting;
};

#endif