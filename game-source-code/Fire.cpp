#include "Fire.h"
#include "global.h"

Fire::Fire()
{
}

void Fire::shoot(const sf::Vector2f& pos, const Direction& direction)
{
    _direction = direction;
    _arrayPos = pos;
}

void Fire::retract()
{
    _squaresOccupied.clear();
}