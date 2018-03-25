#include "smallFunctions.h"
#include "Rock.h"
#include "Harpoon.h"
#include "Monster.h"
#include "Dragon.h"
#include <vector>
#include "TextManager.h"
#include <SFML/Window.hpp>
#include "SplashPresenter.h"


void populateRocks(std::vector<Rock>& rocks)
{
    rocks.push_back(sf::Vector2f(33, 2));
    rocks.push_back(sf::Vector2f(10, 20));
    rocks.push_back(sf::Vector2f(1, 30));
    rocks.push_back(sf::Vector2f(20, 12));
}

void splashScreenRoutine(sf::RenderWindow& window, SplashPresenter& splashPresenter)
{
    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
	splashPresenter.drawElement(window);
    }
}