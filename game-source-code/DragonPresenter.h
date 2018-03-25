#ifndef DRAGONPRESENTER_H
#define DRAGONPRESENTER_H
#include "EnemyPresenter.h"

/**
 * @class DragonPresenter
 * @brief Presentation manager for Dragon
 * @author Benji
 * @date 22/09/2016
 * @file DragonPresenter.h
 */

class DragonPresenter : public EnemyPresenter

{
public:
    /**
     *@brief Constructor sets colour to green
     *@param position The Dragon's position in 2d grid
	 *@param isGhost Boolean determining if ghost is in ghost form or not
     */
    DragonPresenter(const sf::Vector2f& position, const bool& isGhost);
};

#endif