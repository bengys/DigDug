#ifndef DUG_H
#define DUG_H
#include "LivingThing.h"

/**
 * @class Dug
 * @brief Class which manages the Dug character
 * @author Benji
 * @date 22/09/2016
 * @file Dug.h
 */

class Dug : public LivingThing
{
public:
    /**
     * @brief COnstructs Dug with 5 lives and sets his starting position in a tunnel
     */
    Dug();

    /**
     * @brief Gets the direction that Dug was facing in his previous move
     * @return A enum Direction type giving his past direction
     */
    Direction getPastDirection() const;

    /**
     * @brief Get Dug's remaining lives
     * @return Dugs remaining lives
     */
    int getLives() const;

    /**
     * @brief Checks if a collission has occured between Dug's position and another position. If a collission has
     * occured Dug loses a life
     * @param pos x,y co-ords of a point to be checked for collision
     * @return Returns true if the points positions collide, flase otherwise
     */
    virtual bool collisionCheck(const sf::Vector2f& pos) override;

    /**
     * @brief Determine Dug is alive
     * @return
     */
    bool isAlive() const;

private:
    /**
     * @brief Detract a life from Dug's lives
     */
    void kill();

    bool _isAlive;
    int lives;
};

#endif