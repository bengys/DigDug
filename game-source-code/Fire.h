#ifndef FIRE_H
#define FIRE_H
#include <global.h>
#include "Weapon.h"

/**
 * @class Fire
 * @brief Manages logic for fire object
 * @author Benji
 * @date 22/09/2016
 * @file Fire.h
 */

class Fire : public Weapon
{
    friend class Dragon;

public:
    /**
     * @brief Fire is shot at a particular postion and direction
     * @param pos x,y co-ords of Dragon, which in turn defines starting postion of the fire
     * @param direction Direction of the dragon which in turn determines direction in which fire will be shot
     */
    virtual void shoot(const sf::Vector2f& pos, const Direction& direction) override;

private:
    /**
     * @brief Fire's constructor is private as it is only to be created automatically when a Dragon is initialised.
     */
    Fire();

    /**
     * @brief Clear Vector containing x,y co-ords of positions currently occupied by fire
     */
    void retract();
};

#endif