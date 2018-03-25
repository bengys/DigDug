#include "BlockArray.h"
#include "smallFunctions.h"
#include "Monster.h"
#include "Dug.h"
#include "routines.h"
#include "Rock.h"
#include "Harpoon.h"
#include "Dragon.h"
#include <SFML/Window.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(
        sf::VideoMode(arrVars::SCREENWIDTH, arrVars::SCREENHEIGHT), "My window", sf::Style::Fullscreen);
    window.setFramerateLimit(7);
    BlockArray gameBlockArray;
    Harpoon harpoon;
    Dug dug;
    std::vector<Monster> Monsters;
    std::vector<Dragon> dragons;
    std::vector<Rock> rocks;
    populateRocks(rocks);
    generateMonsters(Monsters, dragons);
    SplashPresenter splashPresenter(sf::Vector2f(0, 0));
    TextManager textManager;
    auto startScreenWaiting = true;

    sf::Event event;

    // Main game loop
    while(window.isOpen()) {

	while(window.pollEvent(event)) {
	    if(event.key.code == sf::Keyboard::Escape)
		window.close();
	}

	//Splash screen displayed until user presses 'w'
	if(startScreenWaiting) {
	    splashScreenRoutine(window, splashPresenter);
	    startScreenWaiting = false;
	}

	textManager.livesText(dug.getLives());
	getDugMovement(dug, rocks);
	gameBlockArray.eatBlock(dug.getPosition(), dug.getDirection());
	rockRoutine(rocks, gameBlockArray, Monsters, dug, dragons);
	harpoonRoutine(harpoon, dug);
	monsterRoutine(Monsters, gameBlockArray, dug, harpoon, dragons);
	drawStuff(gameBlockArray, harpoon, Monsters, dug, rocks, dragons, textManager, window);
	if(endGameCheck(dug.isAlive(), Monsters.empty(), dragons.empty(), textManager)) {
	    endGameRoutine(window, textManager);
	    break;
	}
    }

    return 0;
}