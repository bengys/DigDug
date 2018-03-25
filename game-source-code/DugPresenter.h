#ifndef DUGPRESENTER_H
#define DUGPRESENTER_H
#include "ElementPresenter.h"

/**
 * @class DugPresenter
 * @brief Manages presentation of Dug's form
 * @author Benji
 * @date 22/09/2016
 * @file DugPresenter.h
 */

class DugPresenter : public ElementPresenter

{
public:
    DugPresenter(const sf::Vector2f& position);

private:
    /**
     * @brief Size and colour for Dug's shape defined
     */
    virtual void setShapeAttribute() override;
    
	/**
     * @brief Sets Dug's position in terms of pixels
     * @param x x position in grid
     * @param y y position in grid
     */
    virtual void setPixelPosition(const float& x, const float& y) override;
};

#endif