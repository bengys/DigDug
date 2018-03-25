#include "ElementPresenter.h"
#include "global.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

ElementPresenter::ElementPresenter(const sf::Vector2f& position)
    : _arrayPos{ position }
{
    setPixelPosition(_arrayPos.x, _arrayPos.y);
}

void ElementPresenter::drawElement(sf::RenderWindow& window)
{
    window.draw(_Shape);
}

void ElementPresenter::setPixelPosition(const float& x, const float& y)
{
    _pixelPos.x = (arrVars::BLOCKSIZE * _arrayPos.x);
    _pixelPos.y = ((arrVars::BLOCKSIZE * _arrayPos.y) + arrVars::TOPSPACE);
    _Shape.setPosition(_pixelPos.x, _pixelPos.y);
}