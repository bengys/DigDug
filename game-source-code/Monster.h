#ifndef MONSTER_H
#define MONSTER_H
#include "LivingThing.h"
#include "global.h"
#include <vector>

/**
 * @class Monster
 * @brief Manages Monster's game logic
 * @author Benji
 * @date 23/09/2016
 * @file Monster.h
 */

class Monster : public LivingThing
{
public:
    /**
     * @brief Constructed by default to not be a ghost
     */
    Monster();

    /**
     * @brief Monster moves when this function is called. Determines if he will move like a ghost or non-ghost.
     * @param vec vector of enum type  Direction which gives the available directions that the monster can move
     * @param dugPos Dug's x,y co-ords.
     * @param isEmpty Determines whether the current block that the monster occupies is empty or not. Used to determine
     * if Ghost should re-embody
     */
    void movement(std::vector<Direction>& vec, const sf::Vector2f& dugPos, const bool& isEmpty);

    /**
     * @brief Determines if the Monster is in ghost form
     * @return True if in ghost form, false otherwise
     */
    bool isGhost() const;

protected:
    /**
     * @brief Will attempt to make the Monster a ghost based on a random number
     */
    void tryBecomeGhost();

    /**
     * @brief Algorithm for determining the Monster's movement if he is not a ghost
     * @param vec Vector of enum type  Direction which gives the available directions that the monster can move
     * @param  Dug's current x,y co-ords
     */
    void randomMove(std::vector<Direction>& vec, const sf::Vector2f& dugPos);

    /**
     * @brief Movement Algorithm if Monster is a ghost
     * @param dugPos Dug,s x,y co-ords
     * @param isEmpty Determines if the current block the monster is in is solid or empty
     */
    void moveGhost(const sf::Vector2f& dugPos, bool isEmpty);

    /**
     * @brief Used by randomMove function to set directions which Monster can move
     * @param direction The Direction which we are testing.
     * @param vec Vector of enum type  Direction which gives the available directions that the monster can move
     * @return True if the Monster can move in the requested direction, false otherwise
     */
    bool canMoveInDirection(Direction direction, std::vector<Direction>& vec);

    bool _isGhost;
    bool _ghostMoved;
};

#endif