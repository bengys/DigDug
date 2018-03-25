#include <vector>
#include "Monster.h"
#include "BlockArray.h"
#include "Dug.h"
#include "Dragon.h"
#include "Harpoon.h"
#include "Rock.h"
#include "BlockPresenter.h"
#include "MonsterPresenter.h"
#include "DragonPresenter.h"
#include "RockPresenter.h"
#include "DugPresenter.h"
#include "FirePresenter.h"
#include "HarpoonPresenter.h"
#include "BorderPresenter.h"
#include "TextManager.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void drawStuff(BlockArray& gameBlockArray,
    Harpoon& harpoon,
    const std::vector<Monster>& Monsters,
    Dug& dug,
    const std::vector<Rock>& rocks,
    const std::vector<Dragon>& dragons,
    const TextManager& textManager, sf::RenderWindow& window)
{
    window.clear(sf::Color::Cyan);
	
    for(int i = 0; i != arrVars::ARRAYLENGTH; i++) {
	for(int j = 0; j != arrVars::ARRAYBREADTH; j++) {
	    BlockPresenter blockPresenter(sf::Vector2f(i, j), gameBlockArray.getBlock(sf::Vector2f(i, j)).isEmpty());
	    BorderPresenter borderPresenter(
	        sf::Vector2f(i, j), gameBlockArray.getBlock(sf::Vector2f(i, j)).getBorder().getBorderStatus());
	    blockPresenter.drawElement(window);
	    borderPresenter.drawElement(window);
	}
    }

    window.draw(textManager.getText());
    DugPresenter dugPresenter(dug.getPosition());
    dugPresenter.drawElement(window);
    HarpoonPresenter hapPresenter(harpoon.getPosition(), dug.getDirection(), harpoon.isShooting());
    hapPresenter.drawElement(window);

    for(auto monst : Monsters) {
	MonsterPresenter monsterPresenter(monst.getPosition(), monst.isGhost());
	monsterPresenter.drawElement(window);
    }
    for(auto drag : dragons) {
	DragonPresenter dragPresenter(drag.getPosition(), drag.isGhost());
	dragPresenter.drawElement(window);
	FirePresenter firePresenter(drag.getPosition(), drag.getDirection(), drag.isSpitting());
	firePresenter.drawElement(window);
    }

    for(auto rock : rocks) {
	RockPresenter rockpresenter(rock.getPosition());
	rockpresenter.drawElement(window);
    }

    window.display();
}