#ifndef ROCK_H
#define ROCK_H
#include "Element.h"

/**
 * @class Rock
 * @brief Manages logic of rock
 * @author Benji
 * @date 23/09/2016
 * @file Rock.h
 */

class Rock : public Element
{
public:
    /**
    *@brief Sets postion of rock and rock on creation does not automatically fall
    *@param vec The starting x,y co-ords of the rock in the system
    */
    Rock(sf::Vector2f vec);

    /**
     * @brief When called tests if the rock is in a state in which it should fall and based on that changes its co-ords
     * @param isOpenUnderneath Determines if the block underneath the rock is empty or solid
     */
    void fallRoutine(bool isOpenUnderneath);

    /**
     * @brief Determines if the rock is currently in a state of falling
     * @return True if the rock is currently falling, false otherwise
     */
    bool isFalling() const;

    /**
    * @brief Determines if the rock  must be marked for destruction (i.e deleted from Rock Vector)
    * @return True if the rock is at the bottom and must now be destroyed, false otherwise
    */
    bool canDestroyRock() const;

private:
    int _fallDelay;
    bool _isFalling;
    bool _canDestroyRock;
};

#endif