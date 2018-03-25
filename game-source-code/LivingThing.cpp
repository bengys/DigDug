#include "LivingThing.h"

LivingThing::LivingThing()

{
	_arrayPos = sf::Vector2f(0,0);
	_direction = Direction::right;
}

void LivingThing::setStartPosition(const sf::Vector2f& startPos)
{
    _arrayPos = startPos;
}

void LivingThing::move(const Direction& direction)
{
    _pastDirection = _direction;

    switch(direction) {
    case(Direction::left):
	if(_arrayPos.x > 0) {
	    _arrayPos.x = _arrayPos.x - 1;
	}
	_direction = Direction::left;
	break;
    case(Direction::right):
	if(_arrayPos.x < arrVars::ARRAYLENGTH - 1) {
	    _arrayPos.x += 1;
	    _direction = Direction::right;
	}
	break;
    case(Direction::down):
	if(_arrayPos.y < arrVars::ARRAYBREADTH - 1) {
	    _arrayPos.y += 1;
	    _direction = Direction::down;
	}
	break;
    case(Direction::up):
	if(_arrayPos.y > 0) {
	    _arrayPos.y -= 1;
	    _direction = Direction::up;
	}
	break;
    default:
	break;
    }
}

Direction LivingThing::getDirection() const
{
    return _direction;
}

bool LivingThing::collisionCheck(const sf::Vector2f& pos)
{
    if(pos == _arrayPos)
	return true;
    else
	return false;
}