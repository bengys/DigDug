#include "EnemyPresenter.h"
#include "global.h"

EnemyPresenter::EnemyPresenter(const sf::Vector2f& position, const bool& isGhost)
    : ElementPresenter(position)
    , _isGhost(isGhost)
{
}

void EnemyPresenter::setShapeAttribute()
{
    _Shape.setSize(sf::Vector2f(arrVars::BLOCKSIZE - 2, arrVars::BLOCKSIZE - 2));
    if(!_isGhost)
	_Shape.setFillColor(color);
    else {
	_Shape.setFillColor(sf::Color::White);
	_Shape.setOutlineThickness(2);
	_Shape.setOutlineColor(color);
    }
}

void EnemyPresenter::setPixelPosition(const float& x, const float& y)
{
    _pixelPos.x = (arrVars::BLOCKSIZE * _arrayPos.x);
    _pixelPos.y = ((arrVars::BLOCKSIZE * _arrayPos.y) + arrVars::TOPSPACE);
    _Shape.setPosition(_pixelPos.x + 1, _pixelPos.y + 1);
}