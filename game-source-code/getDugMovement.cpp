#include "Dug.h"
#include "Rock.h"
#include <algorithm>
#include <vector>
#include <SFML/Window/Keyboard.hpp>

void getDugMovement(Dug& dug, std::vector<Rock>& rocks)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (std::none_of(rocks.begin(), rocks.end(), [&](Rock rock) {
	   if(rock.getPosition() == sf::Vector2f(dug.getPosition().x - 1, dug.getPosition().y))
	       return true;
	   return false;
       }))) {
	dug.move(Direction::left);
	return;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (std::none_of(rocks.begin(), rocks.end(), [&](Rock rock) {
	   if(rock.getPosition() == sf::Vector2f(dug.getPosition().x + 1, dug.getPosition().y))
	       return true;
	   return false;
       }))) {
	dug.move(Direction::right);
	return;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (std::none_of(rocks.begin(), rocks.end(), [&](Rock rock) {
	   if(rock.getPosition() == sf::Vector2f(dug.getPosition().x, dug.getPosition().y - 1))
	       return true;
	   return false;
       }))) {
	dug.move(Direction::up);
	return;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (std::none_of(rocks.begin(), rocks.end(), [&](Rock rock) {
	   if(rock.getPosition() == sf::Vector2f(dug.getPosition().x, dug.getPosition().y + 1))
	       return true;
	   return false;
       }))) {
	dug.move(Direction::down);
	return;
    }

    return;
}