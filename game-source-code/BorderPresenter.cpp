#include "BorderPresenter.h"
#include "global.h"
#include <vector>

using sf::Vector2f;
using sf::Color;

BorderPresenter::BorderPresenter(const sf::Vector2f& position, const std::vector<Direction>& borders)
    : ElementPresenter(position)

{
    isOpenLeft = false;
    isOpenRight = false;
    isOpenTop = false;
    isOpenBottom = false;
    updateBorderStatus(borders);
    setShapeAttribute();
}

void BorderPresenter::setShapeAttribute()
{
    if(isOpenRight) {
	removeRightBorder();
    } else {
	setRightBorder();
    }
    if(isOpenLeft) {
	removeLeftBorder();
    } else {
	setLeftBorder();
    }
    if(isOpenTop) {
	removeTopBorder();
    } else {
	setTopBorder();
    }
    if(isOpenBottom) {
	removeBottomBorder();
    } else {
	setBottomBorder();
    }
}

void BorderPresenter::updateBorderStatus(const std::vector<Direction>& direcVec)
{
    for(auto direc : direcVec) {
	switch(direc) {
	case(Direction::down):
	    isOpenBottom = true;
	    break;
	case(Direction::up):
	    isOpenTop = true;
	    break;
	case(Direction::left):
	    isOpenLeft = true;
	    break;
	case(Direction::right):
	    isOpenRight = true;
	default:
	    break;
	}
    }
}

void BorderPresenter::drawElement(sf::RenderWindow& window)
{
    window.draw(_topBorder);
    window.draw(_bottomBorder);
    window.draw(_leftBorder);
    window.draw(_rightBorder);
}

void BorderPresenter::setLeftBorder()
{
    // Draw line on left
    _rightBorder.setSize(Vector2f(1, arrVars::BLOCKSIZE));
    _rightBorder.setFillColor(Color::Black);
    _rightBorder.setPosition(_pixelPos.x, _pixelPos.y);
}

void BorderPresenter::setRightBorder()
{
    // Draw Line on right
    _leftBorder.setSize(Vector2f(1, arrVars::BLOCKSIZE));
    _leftBorder.setFillColor(Color::Black);
    _leftBorder.setPosition(_pixelPos.x + arrVars::BLOCKSIZE - 1, _pixelPos.y);
}

void BorderPresenter::setTopBorder()
{
    // Draw line at top
    _topBorder.setSize(Vector2f(arrVars::BLOCKSIZE, 1));
    _topBorder.setFillColor(Color::Black);
    _topBorder.setPosition(_pixelPos.x, _pixelPos.y);
}

void BorderPresenter::setBottomBorder()
{
    // Draw line at bottom
    _bottomBorder.setSize(Vector2f(arrVars::BLOCKSIZE, 1));
    _bottomBorder.setFillColor(Color::Black);
    _bottomBorder.setPosition(_pixelPos.x, _pixelPos.y + arrVars::BLOCKSIZE - 1);
}

void BorderPresenter::removeLeftBorder()
{
    // Erase line on left
    _rightBorder.setSize(Vector2f(1, arrVars::BLOCKSIZE - 2));
    _rightBorder.setFillColor(Color::Yellow);
    _rightBorder.setPosition(_pixelPos.x, _pixelPos.y + 1);
}

void BorderPresenter::removeRightBorder()
{
    // Erase line on right
    _leftBorder.setSize(Vector2f(1, arrVars::BLOCKSIZE - 2));
    _leftBorder.setFillColor(Color::Yellow);
    _leftBorder.setPosition(_pixelPos.x + arrVars::BLOCKSIZE - 1, _pixelPos.y + 1);
}

void BorderPresenter::removeTopBorder()
{
    // Erase line at top
    _topBorder.setSize(Vector2f(arrVars::BLOCKSIZE - 2, 1));
    _topBorder.setFillColor(Color::Yellow);
    _topBorder.setPosition(_pixelPos.x + 1, _pixelPos.y);
}

void BorderPresenter::removeBottomBorder()
{
    _bottomBorder.setSize(Vector2f(arrVars::BLOCKSIZE - 2, 1));
    _bottomBorder.setFillColor(Color::Yellow);
    _bottomBorder.setPosition(_pixelPos.x + 1, _pixelPos.y + arrVars::BLOCKSIZE - 1);
}