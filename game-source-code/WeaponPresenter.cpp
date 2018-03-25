#include "WeaponPresenter.h"
#include "global.h"

using namespace sf;

WeaponPresenter::WeaponPresenter(const sf::Vector2f& position, const Direction& faceDirection, const bool& isShooting)
    : ElementPresenter(position)
    , _faceDirection(faceDirection)
	, _isShooting(isShooting)
{
}

void WeaponPresenter::setShapeAttribute()
{
	_Shape.setFillColor(color);
	switch(_faceDirection) {
	case(Direction::left):
	    shootLeft();
	    break;
	case(Direction::right):
	    shootRight();
	    break;
	case(Direction::up):
	    shootUp();
	    break;
	case(Direction::down):
	    shootDown();
	    break;
	default:
	    break;
	}
}


void WeaponPresenter::shootRight()
{
    _Shape.setSize(Vector2f(2 * arrVars::BLOCKSIZE, _weaponThickness));
    _Shape.setPosition(Vector2f((_arrayPos.x * arrVars::BLOCKSIZE) + arrVars::BLOCKSIZE,
        ((_arrayPos.y + arrVars::TOPARRAYSPACE) * arrVars::BLOCKSIZE) + 4));
}

void WeaponPresenter::shootLeft()
{
    _Shape.setSize(Vector2f(2 * arrVars::BLOCKSIZE, _weaponThickness));
    _Shape.setPosition(Vector2f(
        (_arrayPos.x * arrVars::BLOCKSIZE) - (arrVars::BLOCKSIZE * 2), ((_arrayPos.y + arrVars::TOPARRAYSPACE) * arrVars::BLOCKSIZE) + 4));
}

void WeaponPresenter::shootUp()
{
    _Shape.setSize(Vector2f(_weaponThickness, 2 * arrVars::BLOCKSIZE));
    _Shape.setPosition(Vector2f((_arrayPos.x * arrVars::BLOCKSIZE) + 4, (_arrayPos.y + arrVars::TOPARRAYSPACE - 2) * arrVars::BLOCKSIZE));
}

void WeaponPresenter::shootDown()
{
    _Shape.setSize(Vector2f(_weaponThickness, 2 * arrVars::BLOCKSIZE));
    _Shape.setPosition(
        Vector2f((_arrayPos.x * arrVars::BLOCKSIZE) + 4, ((_arrayPos.y + arrVars::TOPARRAYSPACE) * arrVars::BLOCKSIZE) + arrVars::BLOCKSIZE));
}

