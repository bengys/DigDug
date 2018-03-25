#ifndef BORDER_H
#define BORDER_H

#include "global.h"
#include "Element.h"
#include <vector>

/**
* @class Border
* @brief Border forms the bounds around each block in four directions. MAnages access to indiviudal Block.
* @author Benji Shear
* @date 21/09/16
* @file Border.h
*/

class Border : public Element
{
public:
    friend class Block;
    friend class BlockArray;

    /**
    * @brief Changes status of the borders - open/closed
    * @param direction Direction Dug is facing
    */
    void updateBorder(const Direction& direction);

    /**
    *@brief Get the directions of the sides of the border which are open
    *@return a vector of type Direction containing directions in which the border is open
    */
    std::vector<Direction> getBorderStatus() const;

private:
    /**
     * @brief Initialises border to be closed in all directions
     */
    Border();

    /**
    * @brief  Changes status of a previous block borders when a corner is turned
    * @param presentDirection Direction Dug is currently facing
    * @param pastDirection The direction Dug was previously facing
    */
    void updatePreviousBorder(const Direction& presentDirection, const Direction& pastDirection);

    /**
     * @brief Used to set position of Border. Only determined when Block is created
     * @param arrayPos
     */
    void setArrayPos(const sf::Vector2f& arrayPos);

    bool isOpenLeft;
    bool isOpenRight;
    bool isOpenTop;
    bool isOpenBottom;
};

#endif