#include "SplashPresenter.h"

SplashPresenter::SplashPresenter(const sf::Vector2f& position)
    : ElementPresenter(position)
{
    setShapeAttribute();
}

void SplashPresenter::setShapeAttribute()
{
    if(!_texture.loadFromFile("splash_screen123.png")) {
    }
    _texture.setRepeated(true);
    _sprite.setTexture(_texture);
}

void SplashPresenter::drawElement(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
    window.draw(_sprite);
	window.display();
}
