#ifndef WEAPONPRESENTER_H
#define WEAPONPRESENTER_H
#include "ElementPresenter.h"
#include "global.h"

/**
 * @class WeaponPresenter
 * @brief Base class for management of presentation of weapon forms
 * @author Benji
 * @date 23/09/2016
 * @file WeaponPresenter.h
 */

class WeaponPresenter : public ElementPresenter

{
public:
    /**
     * @brief On construction styles and postion of weapon shape determined
     * @param postion Position of x,y co-ord of start point of weapon
     * @param faceDirection Direction of entity which is shooting weapon
     * @param isShooting Determines if the weapon is being shot and must be therefore displayed
     */
    WeaponPresenter(const sf::Vector2f& position, const Direction& faceDirection, const bool& isShooting);

protected:
    /**
     * @brief Sets style and postion of shape of weapon
     */
    virtual void setShapeAttribute() override;

    /**
     * @brief Sets style/position of a left shooting weapon
     */
    void shootLeft();

    /**
     * @brief Sets style/position of a right shooting weapon
     */
    void shootRight();

    /**
     * @brief Sets style/position of a up shooting weapon
     */
    void shootUp();

    /**
     * @brief Sets style/position of down shooting weapon
     */
    void shootDown();

    unsigned int _weaponThickness;
    sf::Color color;
    Direction _faceDirection;
    bool _isShooting;
};

#endif