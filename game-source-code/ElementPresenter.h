#ifndef DRAW_ELEMENT_H
#define DRAW_ELEMENT_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**
 * @class ElementPresenter
 * @brief Base class for presentation manager of presentation objects
 * @author Benji
 * @date 22/09/2016
 * @file ElementPresenter.h
 */

class ElementPresenter
{

public:
    /**
    *@brief In constructor pixel position of the object to be presented is defined
    *@param position x,y position of object in 2D co-ord system
    */
    ElementPresenter(const sf::Vector2f& position);

    /**
     * @brief Draw element
     * @param window Game window on which element is displayed
     */
    virtual void drawElement(sf::RenderWindow& window);

protected:
    /**
    * @brief Pure virtual funcion which will be overridden to define shape attributes such as size, colour and
    * outline
    * for various elements
    */
    virtual void setShapeAttribute() = 0;

    /**
    * @brief  Sets the element's position in terms of pixels
    * @param x
    * @param y
    */
    virtual void setPixelPosition(const float& x, const float& y);

    // Each elements is a rectangle shape
    sf::RectangleShape _Shape;

    // Keeps track of where the element is in terms of its top left hand corner pixel
    sf::Vector2f _pixelPos;

    sf::Vector2f _arrayPos;
    sf::Color _color;
};

#endif