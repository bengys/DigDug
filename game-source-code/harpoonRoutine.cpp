#include "Dug.h"
#include "Harpoon.h"
#include <SFML/Window/Keyboard.hpp>

void harpoonRoutine(Harpoon& harpoon, Dug& dug)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	harpoon.shoot(dug.getPosition(), dug.getDirection());
    else
	harpoon.withdrawHarpoon();
}