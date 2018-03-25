#include "BlockArray.h"
#include "Rock.h"
#include "Monster.h"
#include "Dug.h"
#include "Dragon.h"
#include <vector>
#include <algorithm>

void cleanRocks(std::vector<Rock>& rocks)
{
    rocks.erase((std::remove_if(rocks.begin(), rocks.end(), [&](Rock& rock) {
	            if(rock.canDestroyRock())
	                return true;
	            return false;
	        })), rocks.end());
}

void dragonRockClash(Rock rock, std::vector<Dragon>& dragVec)
{
    dragVec.erase((std::remove_if(dragVec.begin(), dragVec.end(), [&](Dragon drag) {
	              if(drag.collisionCheck(rock.getPosition()) ||
	                  (sf::Vector2f(drag.getPosition().x, drag.getPosition().y - 1) == rock.getPosition()))
	                  return true;
	              return false;
	          })), dragVec.end());
}

void monsterRockClash(Rock rock, std::vector<Monster>& monstVec)
{
    monstVec.erase((std::remove_if(monstVec.begin(), monstVec.end(), [&](Monster monst) {
	               if(monst.collisionCheck(rock.getPosition()) ||
	                   (sf::Vector2f(monst.getPosition().x, monst.getPosition().y - 1) == rock.getPosition()))
	                   return true;
	               return false;
	           })), monstVec.end());
}

void maintainRock(BlockArray& array, Rock& rock)
{
    array.getBlock(rock.getPosition()).getBorder().updateBorder(Direction::down);
    array.getBlock(rock.getPosition()).changeTypetoEmpty();
    rock.fallRoutine(array.getBlock(sf::Vector2f(rock.getPosition().x, rock.getPosition().y + 1)).isEmpty());
}

void rockRoutine(std::vector<Rock>& rocks,
    BlockArray& array,
    std::vector<Monster>& monstVec,
    Dug& dug,
    std::vector<Dragon>& dragVec)
{
    for(auto&& rock : rocks) {
	maintainRock(array, rock);
	if(rock.isFalling()) {
	    array.getBlock(rock.getPosition()).changeTypetoEmpty();
	    dug.collisionCheck(rock.getPosition());
	    monsterRockClash(rock, monstVec);
	    dragonRockClash(rock, dragVec);
	}
    }
    cleanRocks(rocks);
}
