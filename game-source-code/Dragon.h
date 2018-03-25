#ifndef DRAGON_H
#define DRAGON_H
#include "Monster.h"
#include "Fire.h"

/**
 * @class Dragon
 * @brief Dragon is essentially a Monster object but with the addition of the abiity to spit
 * fire and its colour is different
 * @author Benji
 * @date 22/09/2016
 * @file Dragon.h
 */

class Dragon : public Monster
{
public:
    /**
     * @brief Initialed with its _spitCount reset and to be currently not spitting fire
     */
    Dragon();

    /**
   * @brief When called about 1 in 12 chance of spitting fire. If it does spit fire, it spits for 5 consecutive cycles
   * (or 5 calls of armDragon())
   */
    void armDragon();

    /**
     * @brief Get fire object of dragon. Each dragon has a fire.
     * @return reference to fire object of Dragon
     */
    Fire& getFire();

    /**
     * @brief Determines if the Dragon is currently spitting fire
     * @return true if the Dragon is spitting, false if not
     */
    bool isSpitting() const;

private:
    Fire _fire;

    // When the dragon spits fire, he spits for the number _spitCount game cycles
    unsigned int _spitCount;

    bool _isSpitting;
};

#endif