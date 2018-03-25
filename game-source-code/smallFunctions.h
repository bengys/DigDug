#ifndef SMALLFUNC_H
#define SMALLFUNC_H
#include "Rock.h"
#include "Dug.h"
#include "Block.h"
#include "Harpoon.h"
#include "TextManager.h"
#include "Dragon.h"
#include "BlockArray.h"
#include "Monster.h"
#include "SplashPresenter.h"
#include <vector>
#include <SFML/Window.hpp>


void splashScreenRoutine(sf::RenderWindow& window, SplashPresenter& splashPresenter);
void populateRocks(std::vector<Rock>& rocks);
bool endGameCheck(const bool isDugAlive, const bool monstersDead, const bool dragonsDead, TextManager& textmanager );
void harpoonEnemyClashMonst(Harpoon& harpoon, std::vector<Monster>& enemyVec);
void harpoonEnemyClashDrag(Harpoon& harpoon, std::vector<Dragon>& enemyVec);
void dugMonsterClash(Dug& dug, std::vector<Monster>& monstVec,BlockArray& array );
void dugDragonClash(Dug& dug, std::vector<Dragon>& dragVec, BlockArray& array);
void dugFireClash(Dug& dug, std::vector<Dragon>& dragVec);
#endif