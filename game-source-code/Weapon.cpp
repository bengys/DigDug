#include "Weapon.h"
#include "global.h"
#include <vector>

using namespace sf;
Weapon::Weapon()
{
    _direction = Direction::right;
    _squaresOccupied.clear();
}

std::vector<sf::Vector2f> Weapon::getOccupiedBlocks()
{
    _squaresOccupied.clear();
    switch(_direction) {
    case(Direction::left):
	_squaresOccupied.push_back(Vector2f(_arrayPos.x - 1, _arrayPos.y));
	_squaresOccupied.push_back(Vector2f(_arrayPos.x - 2, _arrayPos.y));
	break;
    case(Direction::right):
	_squaresOccupied.push_back(Vector2f(_arrayPos.x + 1, _arrayPos.y));
	_squaresOccupied.push_back(Vector2f(_arrayPos.x + 2, _arrayPos.y));
	break;
    case(Direction::up):
	_squaresOccupied.push_back(Vector2f(_arrayPos.x, _arrayPos.y - 1));
	_squaresOccupied.push_back(Vector2f(_arrayPos.x, _arrayPos.y - 2));
	break;
    case(Direction::down):
	_squaresOccupied.push_back(Vector2f(_arrayPos.x, _arrayPos.y + 1));
	_squaresOccupied.push_back(Vector2f(_arrayPos.x, _arrayPos.y + 2));
	break;
    default:
	break;
    }
    return _squaresOccupied;
}
