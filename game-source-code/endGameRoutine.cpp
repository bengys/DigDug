#include <SFML/Window.hpp>
#include "Dug.h"
#include "Monster.h"
#include "Dragon.h"
#include "TextManager.h"

void endGameRoutine(sf::RenderWindow& window, const TextManager& textmanager)
{
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
	window.clear(sf::Color::Cyan);
	window.draw(textmanager.getText());
	window.display();
    }
}

bool endGameCheck(const bool isDugAlive, const bool monstersDead, const bool dragonsDead, TextManager& textmanager)
{
    if(!isDugAlive) {
	textmanager.endGameText(false);
	return true;
    }
    if(dragonsDead && monstersDead) {
	textmanager.endGameText(true);
	return true;
    }
    return false;
}