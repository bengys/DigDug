#include "HarpoonPresenter.h"
#include "global.h"

HarpoonPresenter::HarpoonPresenter(const sf::Vector2f& position, const Direction& faceDirection, const bool& isShooting)
    : WeaponPresenter(position, faceDirection, isShooting)
{
    color = sf::Color::Black;
    _weaponThickness = 2;
    if(!_isShooting)
	_Shape.setSize(sf::Vector2f(0, 0));
    else
	setShapeAttribute();
}