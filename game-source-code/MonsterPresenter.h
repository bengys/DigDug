#ifndef MONSTERPRESENTER_H
#define MONSTERPRESENTER_H
#include "EnemyPresenter.h"


/**
 * @class MonsterPresenter
 * @brief Manages presentation of Monster form
 * @author Benji
 * @date 23/09/2016
 * @file MonsterPresenter.h
 */

class MonsterPresenter : public EnemyPresenter

{
public:

/**
 *@brief Initialise colour, position, size and outline
 *@param position x,y co-ords of the Monster current position in the system
 *@param isGhost Determines if the Monster is currently in Ghost form or not
*/ 
    MonsterPresenter(const sf::Vector2f& position, const bool& isGhost);
};

#endif