#include "Monster.h"
#include <vector>
#include <cstdlib>
#include <algorithm>

Monster::Monster()

{
    _isGhost = false;
}

void Monster::randomMove(std::vector<Direction>& vec, const sf::Vector2f& dugPos)
{
    bool moveDown = false;
    bool moveUp = false;
    bool moveLeft = false;
    bool moveRight = false;

    if(canMoveInDirection(Direction::down, vec))
	moveDown = true;

    if(canMoveInDirection(Direction::up, vec))
	moveUp = true;

    if(canMoveInDirection(Direction::left, vec))
	moveLeft = true;

    if(canMoveInDirection(Direction::right, vec))
	moveRight = true;

    switch(vec.size()) {
    case(0):
	break;
    case(1):
	move(vec[0]);
	break;
    case(2):
	if(canMoveInDirection(_direction, vec))
	    move(_direction);
	else
	    move(vec[rand() % 2]);
	break;
    case(3):
    case(4):
	if(dugPos.y > _arrayPos.y && moveDown) {
	    move(Direction::down);
	    break;
	}
	if(dugPos.y < _arrayPos.y && moveUp) {
	    move(Direction::up);
	    break;
	}
	if(dugPos.x < _arrayPos.x && moveLeft) {
	    move(Direction::left);
	    break;
	}
	if(dugPos.x > _arrayPos.x && moveRight) {
	    move(Direction::right);
	    break;
	}
	break;
    default:
	break;
    }
}

void Monster::tryBecomeGhost()
{
    if(rand() % 120 == 5) {
	_isGhost = true;
    }
}

void Monster::moveGhost(const sf::Vector2f& dugPos, bool isEmpty)
{

    if(isEmpty && _ghostMoved) {
	_isGhost = false;
	_ghostMoved = false;
	return;
    }

    if(dugPos.y > _arrayPos.y) {
	move(Direction::down);
    }
    if(dugPos.y < _arrayPos.y) {
	move(Direction::up);
    }
    if(dugPos.x < _arrayPos.x) {
	move(Direction::left);
    }
    if(dugPos.x > _arrayPos.x) {
	move(Direction::right);
    }

    _ghostMoved = true;
}

bool Monster::isGhost() const
{
    if(_isGhost)
	return true;
    else
	return false;
}

bool Monster::canMoveInDirection(Direction direction, std::vector<Direction>& vec)
{
    std::vector<Direction>::iterator it;
    it = std::find(vec.begin(), vec.end(), direction);
    if(it != vec.end())
	return true;
    else
	return false;
}

void Monster::movement(std::vector<Direction>& vec, const sf::Vector2f& dugPos, const bool& isEmpty)
{
    tryBecomeGhost();
    if(_isGhost)
	moveGhost(dugPos,isEmpty);
    else
	randomMove(vec,dugPos);
}