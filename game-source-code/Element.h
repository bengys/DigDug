#ifndef ELEMENT_H
#define ELEMENT_H
#include <vector>
#include <SFML/System/Vector2.hpp>

/**
 * @class Element
 * @brief Base class for numerous game logic objects
 * @author Benji
 * @date 22/09/2016
 * @file Element.h
 */

class Element
{
public:
    /**
     * @brief Return x,y co-ords of object on the grid
     * @return x,y co-ords of type Vector2f
     */
    sf::Vector2f getPosition() const;

protected:
    /**
    *@brief By defaults defines co-ords at 0,0
    */
    Element();
 
   // Keeps track of x,y position of element in the co-ord system
    sf::Vector2f _arrayPos;
};

#endif