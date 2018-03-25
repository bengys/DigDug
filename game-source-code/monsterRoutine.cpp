#include <vector>
#include <algorithm>
#include "BlockArray.h"
#include "Monster.h"
#include "Dragon.h"
#include "Dug.h"
#include "Harpoon.h"

void harpoonEnemyClashMonst(Harpoon& harpoon, std::vector<Monster>& enemyVec)
{
    auto vec = harpoon.getOccupiedBlocks();
    enemyVec.erase((std::remove_if(enemyVec.begin(), enemyVec.end(), [&](Monster enemy) {
	               for(auto point : vec)
	                   if(enemy.collisionCheck(point))
		               return true;
	               return false;
	           })), enemyVec.end());
}

void harpoonEnemyClashDrag(Harpoon& harpoon, std::vector<Dragon>& enemyVec)
{
    {
	auto vec = harpoon.getOccupiedBlocks();
	enemyVec.erase((std::remove_if(enemyVec.begin(), enemyVec.end(), [&](Monster enemy) {
	                   for(auto point : vec)
		               if(enemy.collisionCheck(point))
		                   return true;
	                   return false;
	               })), enemyVec.end());
    }
}

void dugMonsterClash(Dug& dug, std::vector<Monster>& monstVec, BlockArray& array)
{
    // check if Dug has been eaten by monster
    // and moves monster
    for(auto&& monst : monstVec) {
	auto direcVec = array.getAdjacentOpen(monst.getPosition());
	monst.movement(direcVec, dug.getPosition(), array.getBlock(monst.getPosition()).isEmpty());
	if(dug.collisionCheck(monst.getPosition()))
	    break;
    }
}

void dugDragonClash(Dug& dug, std::vector<Dragon>& dragVec, BlockArray& array)
{
    for(auto&& drag : dragVec) {
	auto direcVec = array.getAdjacentOpen(drag.getPosition());
	drag.movement(direcVec, dug.getPosition(), array.getBlock(drag.getPosition()).isEmpty());
	drag.armDragon();
	if(dug.collisionCheck(drag.getPosition()))
	    break;
    }
}

void dugFireClash(Dug& dug, std::vector<Dragon>& dragVec)
{
    // Check if Dug has been burnt by fire...
    for(auto&& drag : dragVec) {
	drag.armDragon();
	auto vec = drag.getFire().getOccupiedBlocks();
	for(auto&& point : vec) {
	    if(dug.collisionCheck(point))
		break;
	}
    }
}


void monsterRoutine(std::vector<Monster>& monstVec,
    BlockArray& array,
    Dug& dug,
    Harpoon& harpoon,
    std::vector<Dragon>& dragVec)
{

    dugMonsterClash(dug, monstVec, array);
    dugDragonClash(dug, dragVec, array);
    harpoonEnemyClashMonst(harpoon, monstVec);
    harpoonEnemyClashDrag(harpoon, dragVec);
	dugFireClash(dug,dragVec);

}
