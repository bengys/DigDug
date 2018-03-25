#include "Harpoon.h"
#include "global.h"
#include <vector>

Harpoon::Harpoon()
{
    _canShoot = true;
    _isShooting = false;
}

void Harpoon::shoot(const sf::Vector2f& pos, const Direction& direction)
{
    if(_canShoot) {
	_isShooting = true;
	_direction = direction;
	_arrayPos = pos;
	_canShoot = false;
    } else {
	withdrawHarpoon();
	_canShoot = true;
    }
}

bool Harpoon::isShooting() const
{
    if(_isShooting)
	return true;
    else
	return false;
}

void Harpoon::withdrawHarpoon()
{
    _isShooting = false;
	_squaresOccupied.clear();
    _direction = Direction::up;
    _arrayPos = sf::Vector2f(0, 0);
}