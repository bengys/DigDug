#include "Element.h"
#include "global.h"

Element::Element()
{
    _arrayPos = sf::Vector2f(0, 0);
}

sf::Vector2f Element::getPosition() const
{
    return _arrayPos;
}
