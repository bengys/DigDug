#include "global.h"
#include "Border.h"

Border::Border()
{
    // All directions initialised to a closed status
    isOpenLeft = false;
    isOpenRight = false;
    isOpenTop = false;
    isOpenBottom = false;
}

void Border::setArrayPos(const sf::Vector2f& arrayPos)
{
    _arrayPos = arrayPos;
}

void Border::updatePreviousBorder(const Direction& presentDirection, const Direction& pastDirection)
{
    // Check if a corner has been turned (i.e previous and past direction do not match)
    // If a corner has been changed then the borders of previous block from which Dug has travelled has to be set open
    if(presentDirection != pastDirection) {
	switch(presentDirection) {
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

void Border::updateBorder(const Direction& direction)
{
    // If Dug is facing a particular direction the borders in front and behind him are closed
    if(direction == Direction::left || direction == Direction::right) {
	isOpenRight = true;
	isOpenLeft = true;
    } else {
	isOpenTop = true;
	isOpenBottom = true;
    }
}

std::vector<Direction> Border::getBorderStatus() const
{
    std::vector<Direction> vec;
    if(isOpenRight)
	vec.push_back(Direction::right);
    if(isOpenLeft)
	vec.push_back(Direction::left);
    if(isOpenTop)
	vec.push_back(Direction::up);
    if(isOpenBottom)
	vec.push_back(Direction::down);

    return vec;
}
