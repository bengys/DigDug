#ifndef HARPOONPRESENTER_H
#define HARPOONPRESENTER_H
#include "WeaponPresenter.h"
#include "global.h"

/**
 * @class HarpoonPresenter
 * @brief Manages presentation of Harpoon form
 * @author Benji
 * @date 22/09/2016
 * @file HarpoonPresenter.h
 *
 */

class HarpoonPresenter : public WeaponPresenter

{
public:
    /**
     * @brief Constructor sets attributes unique to Harpoon based on position direction and whether harpoon is being
     * shot */
    HarpoonPresenter(const sf::Vector2f& position, const Direction& faceDirection, const bool& isShooting);
};

#endif