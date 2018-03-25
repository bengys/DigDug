#ifndef ROCKPRESENTER_H
#define ROCKPRESENTER_H
#include "ElementPresenter.h"

/**
 * @class RockPresenter
 * @brief Manages presentation of rock form
 * @author Benji
 * @date 23/09/2016
 * @file RockPresenter.h
 */

class RockPresenter : public ElementPresenter

{
public:
    /**
    *@brief Constructs to rock form with its presentation attributes
    *@param postion x,y co-ords of rock in system
    */
    RockPresenter(const sf::Vector2f& position);

private:
    /**
     * @brief Set attributes of rock form
     */
    virtual void setShapeAttribute() override;
};

#endif