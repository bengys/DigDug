#include "FirePresenter.h"
#include "global.h"

FirePresenter::FirePresenter(const sf::Vector2f& position, const Direction& faceDirection, const bool& isSpitting)
    : WeaponPresenter(position, faceDirection, isSpitting)
{
    color = sf::Color(250, 150, 100);
    _weaponThickness = 8;
    if(!_isShooting)
	_Shape.setSize(sf::Vector2f(0, 0));
    else
	setShapeAttribute();
}