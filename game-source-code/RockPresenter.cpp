#include "RockPresenter.h"
#include "global.h"

RockPresenter::RockPresenter(const sf::Vector2f& position)
    : ElementPresenter(position)
{
    setShapeAttribute();
}

void RockPresenter::setShapeAttribute()
{
    _Shape.setSize(sf::Vector2f(arrVars::BLOCKSIZE, arrVars::BLOCKSIZE));
    _Shape.setFillColor(sf::Color::Black);
}
