#include "DugPresenter.h"
#include "global.h"

DugPresenter::DugPresenter(const sf::Vector2f& position)
    : ElementPresenter(position)
{
    setShapeAttribute();
}

void DugPresenter::setShapeAttribute()
{
    _Shape.setSize(sf::Vector2f(arrVars::BLOCKSIZE - 2, arrVars::BLOCKSIZE - 2));
	_Shape.setFillColor(sf::Color::Blue);
}

void DugPresenter::setPixelPosition(const float& x, const float& y)
{
    _pixelPos.x = (arrVars::BLOCKSIZE * _arrayPos.x);
    _pixelPos.y = ((arrVars::BLOCKSIZE * _arrayPos.y) + arrVars::TOPSPACE);
    _Shape.setPosition(_pixelPos.x + 1, _pixelPos.y + 1);
}