#ifndef FIREPRESENTER_H
#define FIREPRESENTER_H
#include "WeaponPresenter.h"
#include "global.h"

/**
 * @class FirePresenter
 * @brief Manages presentation of Fire form
 * @author Benji
 * @date 22/09/2016
 * @file FirePresenter.h
 */

class FirePresenter : public WeaponPresenter

{
public:
    /**
     *@brief Set shape attributes depending on whether the fire is being shot or not
     *@position x,y co-ord of fire starting position
     *@faceDirection Direction in which the fire is being pointed
     *@isShooting Determines if fire is being shot this game cycles or not.
    */
    FirePresenter(const sf::Vector2f& position, const Direction& faceDirection, const bool& isShooting);
};

#endif