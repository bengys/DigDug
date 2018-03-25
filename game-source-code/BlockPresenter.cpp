#include "BlockPresenter.h"
#include "global.h"

BlockPresenter::BlockPresenter(const sf::Vector2f& position, bool isEmpty)
    : ElementPresenter(position)
    , _isEmpty(isEmpty)
{
    setShapeAttribute();
}

void BlockPresenter::setShapeAttribute()
{
    _Shape.setSize(sf::Vector2f(arrVars::BLOCKSIZE, arrVars::BLOCKSIZE));
    if(_isEmpty)
	_Shape.setFillColor(sf::Color::Yellow);
    else
	_Shape.setFillColor(sf::Color(128, 80, 32));
}