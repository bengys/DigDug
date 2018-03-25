#ifndef LIVING_THING_H
#define LIVING_THING_H
#include "global.h"
#include "Element.h"

/**
 * @class LivingThing
 * @brief Base class for all creatures - ie Dug and Monsters
 * @author Benji
 * @date 22/09/2016
 * @file LivingThing.h
 */

class LivingThing : public Element
{
public:
    /**
     * @brief LivingThing is created in an "alive" form and by default at 0,0
     */
    LivingThing();

    /**
     * @brief set starting postion of LivingThing in the grid
     * @param startPos x,y start co-ords in Vector2f form
     */
    void setStartPosition(const sf::Vector2f& startPos);

    /**
     * @brief Move LivingThing in a particular direction by changing x,y co-ords
     * @param direction enum type Direction which determines x,y direction be moved
     */

    void move(const Direction& direction);
    /**
     * @brief Get the current direction which LivingThing is facing
     * @return enum type Direction in which the LivingThing is facing
     */
    Direction getDirection() const;

    /**
     * @brief Check if x,y co-ords of LivingThing is as another x,y co-ord
     * @param pos x,y co-ord to be checked with LivingThing's co-ords
     * @return True if a collission has occurred, false otherwise
     */
    virtual bool collisionCheck(const sf::Vector2f& pos);

protected:
    Direction _direction;
    Direction _pastDirection;
};

#endif