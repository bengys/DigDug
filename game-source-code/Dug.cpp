#include "Dug.h"

Dug::Dug()
{
    _isAlive = true;
    _arrayPos = sf::Vector2f(5, 10);
    lives = 5;
}

int Dug::getLives() const
{
    return lives;
}

Direction Dug::getPastDirection() const
{
    return _pastDirection;
}

bool Dug::collisionCheck(const sf::Vector2f& pos)
{
    if(pos == _arrayPos) {
	kill();
	return true;
    } else
	return false;
}

void Dug::kill()
{
    lives--;
    if(lives < 0) {
	_isAlive = false;
	return;
    }
    _arrayPos.x = lives * 10;
    _arrayPos.y = arrVars::ARRAYBREADTH - 1;
    move(_direction);
}

bool Dug::isAlive() const
{
    if(_isAlive)
	return true;
    else
	return false;
}