#ifndef BORDERPRESENTER_H
#define BORDERPRESENTER_H
#include "ElementPresenter.h"
#include "global.h"

/**
 * @class BorderPresenter
 * @brief Used to present a Border using SFML graphics library
 * @author Benji
 * @date 22/09/2016
 * @file BorderPresenter.h
 */

class BorderPresenter : public ElementPresenter

{
public:
    /**
     * @brief Creates object to draw a Border
     * @param position Position of the border in array
     * @param borders Vector of directions of the border which are currently open
     */
    BorderPresenter(const sf::Vector2f& position, const std::vector<Direction>& borders);

    /**
     * @brief Draw four border shapes in the four directions
     * @param window Game window
     */
    virtual void drawElement(sf::RenderWindow& window) override;

private:
    /**
     * @brief Sets or removes border shapes depending on directions which are open/closed
     */
    virtual void setShapeAttribute() override;

    /**
     * @brief Update directions of border which are currently open
     * @param direcVec Vector of type Direction of Directions which are currently open
     */
    void updateBorderStatus(const std::vector<Direction>& direcVec);

    // Sets colour/shape pixels to a  closed appearance
    void setLeftBorder();
    void setRightBorder();
    void setTopBorder();
    void setBottomBorder();

    // Sets colour/shape pixels to an open appearance
    void removeLeftBorder();
    void removeRightBorder();
    void removeTopBorder();
    void removeBottomBorder();

    // keeps track of status of border
    bool isOpenLeft;
    bool isOpenRight;
    bool isOpenTop;
    bool isOpenBottom;

    sf::RectangleShape _topBorder;
    sf::RectangleShape _bottomBorder;
    sf::RectangleShape _leftBorder;
    sf::RectangleShape _rightBorder;
};

#endif