#include <vector>
#include "Monster.h"
#include "Dragon.h"
#include "BlockArray.h"
#include "Dug.h"
#include "Harpoon.h"
#include "Rock.h"
#include "TextManager.h"
#include <SFML/Window.hpp>


void harpoonRoutine(Harpoon& harpoon, Dug& dug);
void rockRoutine(std::vector<Rock>& rocks,
    BlockArray& array,
    std::vector<Monster>& monstVec,
    Dug& dug,
    std::vector<Dragon>& dragVec);
void monsterRoutine(std::vector<Monster>& monstVec,
    BlockArray& array,
    Dug& dug,
    Harpoon& harpoon,
    std::vector<Dragon>& dragVec);
void getDugMovement(Dug& dug, std::vector<Rock>& rocks);
void generateMonsters(std::vector<Monster>& monstVec, std::vector<Dragon>& dragonVec);
void drawStuff(BlockArray& gameBlockArray,
    Harpoon& harpoon,
    const std::vector<Monster>& Monsters,
    Dug& dug,
    const std::vector<Rock>& rocks,
    const std::vector<Dragon>& dragons,
    const TextManager& textManager,
    sf::RenderWindow& window);

void endGameRoutine(sf::RenderWindow& window, const TextManager& textmanager);