#include <gtest/gtest.h>
#include "LivingThing.h"
#include "global.h"
#include "Monster.h"
#include "Dug.h"
#include "Dragon.h"
#include "Block.h"
#include "Harpoon.h"
#include "BlockArray.h"
#include "Rock.h"
#include <vector>

using namespace std;
using namespace sf;

TEST(Block, createsFirstBlockAt00)
{
    Block block0;
    EXPECT_EQ(sf::Vector2f(0, 0), block0.getPosition());
}

TEST(Block, createsBlocksVertically)
{
    Block block1;
    Block block2;
    Block block3;
    Block block4;
    EXPECT_EQ(sf::Vector2f(0, 1), block1.getPosition());
    EXPECT_EQ(sf::Vector2f(0, 2), block2.getPosition());
    EXPECT_EQ(sf::Vector2f(0, 3), block3.getPosition());
    EXPECT_EQ(sf::Vector2f(0, 4), block4.getPosition());
}

TEST(Block, wrapsUpToTopAfterBlockCreatedAtBottomOfArray)
{
    std::vector<Block> blockVec5to31;
    blockVec5to31.resize(27);
    Block block32;
    EXPECT_EQ(sf::Vector2f(0, 32), block32.getPosition());
    Block block33;
    EXPECT_EQ(sf::Vector2f(1, 0), block33.getPosition());
}

TEST(Block, initialisesToSolidType)
{
    Block testBlock;
    EXPECT_FALSE(testBlock.isEmpty());
}

TEST(Block, changeTypeToEmptyCorrectly)
{
    Block testBlock;
    testBlock.changeTypetoEmpty();
    EXPECT_TRUE(testBlock.isEmpty());
}

TEST(BlockArray, createsBlockArrayToExpectedLength)
{
    BlockArray blockArray;
    EXPECT_NO_THROW(blockArray.getBlock(sf::Vector2f(arrVars::ARRAYLENGTH, 0)));
    EXPECT_THROW(blockArray.getBlock(sf::Vector2f(arrVars::ARRAYLENGTH + 1, 0)), BlockOutOfBounds);
}

TEST(BlockArray, createsBlockArrayToExpectedBreadth)
{
    BlockArray blockArray;
    EXPECT_NO_THROW(blockArray.getBlock(sf::Vector2f(0, arrVars::ARRAYBREADTH)));
    EXPECT_THROW(blockArray.getBlock(sf::Vector2f(0, arrVars::ARRAYBREADTH + 1)), BlockOutOfBounds);
}

TEST(BlockArray, cannotRequestBlockInNegativePosition)
{
    BlockArray blockArray;
    EXPECT_THROW(blockArray.getBlock(sf::Vector2f(-1, -1)), BlockOutOfBounds);
}


TEST(BlockArray, getsBlockAtcorrectCoordinatesRequested)
{
    BlockArray array;
    EXPECT_EQ(Vector2f(10, 10), array.getBlock(Vector2f(10, 10)).getPosition());
}

TEST(BlockArray, returnsEmptyVectorWhenNoAdjacentBlocksOpenNextToRequestedBlocks)
{
    BlockArray array;
    unsigned int i = 0;
    EXPECT_EQ(i, (array.getAdjacentOpen(Vector2f(2, 2)).size()));
    ;
}

TEST(BlockArray, returnsVectorofOneELementWhenOnlyOneAdjacentBlockisOpenNextToRequestedBlocks)
{
    BlockArray array;
    array.getBlock(Vector2f(2, 2)).getBorder().updateBorder(Direction::right);
    array.getBlock(Vector2f(3, 2)).getBorder().updateBorder(Direction::right);
    unsigned int i = 1;
    EXPECT_EQ(i, (array.getAdjacentOpen(Vector2f(2, 2)).size()));
    ;
}

TEST(BlockArray, returnsVectoroftwoELementWhenTwoAdjacentBlocksareOpenNextToRequestedBlocks)
{
    BlockArray array;
    array.getBlock(Vector2f(2, 2)).getBorder().updateBorder(Direction::right);
    array.getBlock(Vector2f(3, 2)).getBorder().updateBorder(Direction::right);
    array.getBlock(Vector2f(1, 2)).getBorder().updateBorder(Direction::right);
    unsigned int i = 2;
    EXPECT_EQ(i, (array.getAdjacentOpen(Vector2f(2, 2)).size()));
    ;
}

TEST(BlockArray, returnsVectorofthreeELementsWhenThreeAdjacentBlocksareOpenNextToRequestedBlocks)
{
    BlockArray array;
    array.getBlock(Vector2f(2, 2)).getBorder().updateBorder(Direction::right);
    array.getBlock(Vector2f(2, 2)).getBorder().updateBorder(Direction::down);
    array.getBlock(Vector2f(3, 2)).getBorder().updateBorder(Direction::right);
    array.getBlock(Vector2f(1, 2)).getBorder().updateBorder(Direction::right);
    array.getBlock(Vector2f(2, 1)).getBorder().updateBorder(Direction::up);
    unsigned int i = 3;
    EXPECT_EQ(i, (array.getAdjacentOpen(Vector2f(2, 2)).size()));
    ;
}

TEST(BlockArray, returnsVectorofFourELementsWhenFourAdjacentBlocksareOpenNextToRequestedBlocks)
{
    BlockArray array;
    array.getBlock(Vector2f(2, 2)).getBorder().updateBorder(Direction::right);
    array.getBlock(Vector2f(2, 2)).getBorder().updateBorder(Direction::down);
    array.getBlock(Vector2f(3, 2)).getBorder().updateBorder(Direction::right);
    array.getBlock(Vector2f(1, 2)).getBorder().updateBorder(Direction::right);
    array.getBlock(Vector2f(2, 1)).getBorder().updateBorder(Direction::down);
    array.getBlock(Vector2f(2, 3)).getBorder().updateBorder(Direction::down);
    unsigned int i = 4;
    EXPECT_EQ(i, (array.getAdjacentOpen(Vector2f(2, 2)).size()));
    ;
}

TEST(Border, whenCreatedAllBordersAreClosed)
{
    Block block;
    std::vector<Direction> vec = block.getBorder().getBorderStatus();
    unsigned int i = 0;
    EXPECT_EQ(i, vec.size());
}

TEST(Border, whenUpdateBordersAndDugIsFacingLeftBordersAreOpenedToTheRightAndTheLeftOfTheBlock)
{
    Block block;
    block.getBorder().updateBorder(Direction::left);
    std::vector<Direction> vec = block.getBorder().getBorderStatus();
    unsigned int i = 2;
    EXPECT_EQ(i, vec.size());
    EXPECT_TRUE((vec[0] == Direction::left) || (vec[0] == Direction::right));
    EXPECT_TRUE((vec[1] == Direction::left) || (vec[1] == Direction::right));
}

TEST(Border, whenUpdateBordersAndDugIsFacingRightBordersAreOpenedToTheRightAndTheLeftOfTheBlock)
{
    Block block;
    block.getBorder().updateBorder(Direction::right);
    std::vector<Direction> vec = block.getBorder().getBorderStatus();
    unsigned int i = 2;
    EXPECT_EQ(i, vec.size());
    EXPECT_TRUE((vec[0] == Direction::left) || (vec[0] == Direction::right));
    EXPECT_TRUE((vec[1] == Direction::left) || (vec[1] == Direction::right));
}

TEST(Border, whenUpdateBordersAndDugIsFacingUpBordersAreOpenedToTheRightAndTheLeftOfTheBlock)
{
    Block block;
    block.getBorder().updateBorder(Direction::up);
    std::vector<Direction> vec = block.getBorder().getBorderStatus();
    unsigned int i = 2;
    EXPECT_EQ(i, vec.size());
    EXPECT_TRUE((vec[0] == Direction::up) || (vec[0] == Direction::down));
    EXPECT_TRUE((vec[1] == Direction::up) || (vec[1] == Direction::down));
}

TEST(Border, whenUpdateBordersAndDugIsFacingDownBordersAreOpenedToTheRightAndTheLeftOfTheBlock)
{
    Block block;
    block.getBorder().updateBorder(Direction::down);
    std::vector<Direction> vec = block.getBorder().getBorderStatus();
    unsigned int i = 2;
    EXPECT_EQ(i, vec.size());
    EXPECT_TRUE((vec[0] == Direction::up) || (vec[0] == Direction::down));
    EXPECT_TRUE((vec[1] == Direction::up) || (vec[1] == Direction::down));
}

TEST(LivingThing, LTstartsAtPositionItIsSetToStartAt)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 10));
    EXPECT_EQ(Vector2f(10, 10), LT.getPosition());
}


TEST(LivingThing, LTmovesTotheLeftCorrectly)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 10));
    LT.move(Direction::left);
    EXPECT_EQ(Vector2f(9, 10), LT.getPosition());
}

TEST(LivingThing, LTcannotMoveTotheLeftIfPositionedAtLeftEdgeOfArray)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(0, 10));
    LT.move(Direction::left);
    EXPECT_EQ(Vector2f(0, 10), LT.getPosition());
}

TEST(LivingThing, LTmovesTotheRightCorrectly)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 10));
    LT.move(Direction::right);
    EXPECT_EQ(Vector2f(11, 10), LT.getPosition());
}

TEST(LivingThing, LTcannotMoveTotheRightIfPositionedAtRightEdgeOfArray)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(arrVars::ARRAYLENGTH - 1, 10));
    LT.move(Direction::right);
    EXPECT_EQ(Vector2f(arrVars::ARRAYLENGTH - 1, 10), LT.getPosition());
}

TEST(LivingThing, LTmovesDownCorrectly)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 10));
    LT.move(Direction::down);
    EXPECT_EQ(Vector2f(10, 11), LT.getPosition());
}

TEST(LivingThing, LTcannotMoveDownwardsIfPositionedAtBottomEdgeOfArray)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, arrVars::ARRAYBREADTH - 1));
    LT.move(Direction::down);
    EXPECT_EQ(Vector2f(10, arrVars::ARRAYBREADTH - 1), LT.getPosition());
}

TEST(LivingThing, LTmovesUpwardsCorrectly)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 10));
    LT.move(Direction::up);
    EXPECT_EQ(Vector2f(10, 9), LT.getPosition());
}

TEST(LivingThing, LTcannotMoveUpwardsIfPositionedAtTopEdgeOfArray)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 0));
    LT.move(Direction::up);
    EXPECT_EQ(Vector2f(10, 0), LT.getPosition());
}

TEST(LivingThing, ifLTMovesInARightDirectionLTsDirectionBecomesThatDirection)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 10));
    LT.move(Direction::right);
    EXPECT_EQ(Direction::right, LT.getDirection());
}

TEST(LivingThing, ifLTMovesInALeftDirectionLTsDirectionBecomesThatDirection)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 10));
    LT.move(Direction::left);
    EXPECT_EQ(Direction::left, LT.getDirection());
}

TEST(LivingThing, ifLTMovesInAnUpDirectionLTsDirectionBecomesThatDirection)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 10));
    LT.move(Direction::up);
    EXPECT_EQ(Direction::up, LT.getDirection());
}

TEST(LivingThing, ifLTMovesInADownDirectionLTsDirectionBecomesThatDirection)
{
    LivingThing LT;
    LT.setStartPosition(Vector2f(10, 10));
    LT.move(Direction::down);
    EXPECT_EQ(Direction::down, LT.getDirection());
}

TEST(LivingThing, ifLTPositionEqualsThatOfAnotherLTCollissionOccurs)
{
    LivingThing LT1;
    LivingThing LT2;
    LT1.setStartPosition(Vector2f(10, 10));
    LT2.setStartPosition(Vector2f(10, 10));
    EXPECT_TRUE(LT1.collisionCheck(LT2.getPosition()));
}

TEST(LivingThing, ifLTPositionNotEqualToThatOfAnotherLTCollissionDoesntOccur)
{
    LivingThing LT1;
    LivingThing LT2;
    LT1.setStartPosition(Vector2f(10, 10));
    LT2.setStartPosition(Vector2f(11, 11));
    EXPECT_FALSE(LT1.collisionCheck(LT2.getPosition()));
}

TEST(LivingThing, if2LTsHaveSameXpositionButDifferentYNoCollisionOccurs)
{
    LivingThing LT1;
    LivingThing LT2;
    LT1.setStartPosition(Vector2f(10, 10));
    LT2.setStartPosition(Vector2f(10, 11));
    EXPECT_FALSE(LT1.collisionCheck(LT2.getPosition()));
}

TEST(LivingThing, if2LTsHaveSameYpositionButDifferentXNoCollisionOccurs)
{
    LivingThing LT1;
    LivingThing LT2;
    LT1.setStartPosition(Vector2f(10, 10));
    LT2.setStartPosition(Vector2f(11, 10));
    EXPECT_FALSE(LT1.collisionCheck(LT2.getPosition()));
}

TEST(Dragon, dragonIsNotSpittingFireUponCreation)
{
    Dragon dragon;
    EXPECT_FALSE(dragon.isSpitting());
}

TEST(Dragon, dragonSpitsFireSometimes)
{
    Dragon dragon;
    for(auto i = 0; i < 300; i++) {
	dragon.armDragon();
	if(dragon.isSpitting())
	    break;
    }
    EXPECT_TRUE(dragon.isSpitting());
}

TEST(Dragon, OnceDragonBeginsSpittingSheWillSpitForFiveConsecutiveCycles)
{
    Dragon dragon;
    auto spitcount = 0;
    while(!dragon.isSpitting()) {
	dragon.armDragon();
    }
    spitcount++;
    while(dragon.isSpitting()) {
	dragon.armDragon();
	spitcount++;
    }
    EXPECT_EQ(5, spitcount);
}

TEST(Dug, dugBeginsGameWithFiveLives)
{
    Dug dug;
    EXPECT_EQ(5, dug.getLives());
}

TEST(Dug, ifDugCollidesWithSomethingHeLoosesALife)
{
    Dug dug;
    dug.collisionCheck(dug.getPosition());
    EXPECT_EQ(4, dug.getLives());
    dug.collisionCheck(dug.getPosition());
    EXPECT_EQ(3, dug.getLives());
    dug.collisionCheck(dug.getPosition());
    EXPECT_EQ(2, dug.getLives());
}

TEST(Dug, ifDugDoesNotCollideWithSomethingHeDoesntLooseALife)
{
    Dug dug;
    dug.setStartPosition(Vector2f(10, 10));
    dug.collisionCheck(Vector2f(20, 10));
    EXPECT_EQ(5, dug.getLives());
    dug.collisionCheck(Vector2f(10, 20));
    EXPECT_EQ(5, dug.getLives());
}

TEST(Dug, dugBecomesDeadAfterSixCollissions)
{
    Dug dug;
    for(auto i = 0; i != 5; i++) {
	dug.collisionCheck(dug.getPosition());
	EXPECT_TRUE(dug.isAlive());
    }
    dug.collisionCheck(dug.getPosition());
    EXPECT_FALSE(dug.isAlive());
}

TEST(Weapon, whenShootTotheRightWeaponOccupiesTheTwoBlocksToTheRight)
{
    Harpoon harpoon;
    harpoon.shoot(Vector2f(10, 10), Direction::right);
    auto vec = harpoon.getOccupiedBlocks();
    EXPECT_TRUE(vec[0] == Vector2f(11, 10) || vec[0] == Vector2f(12, 10));
    EXPECT_TRUE(vec[1] == Vector2f(11, 10) || vec[1] == Vector2f(12, 10));
}

TEST(Weapon, whenShootTotheLeftWeaponOccupiesTheTwoBlocksToTheLeft)
{
    Harpoon harpoon;
    harpoon.shoot(Vector2f(10, 10), Direction::left);
    auto vec = harpoon.getOccupiedBlocks();
    EXPECT_TRUE(vec[0] == Vector2f(9, 10) || vec[0] == Vector2f(8, 10));
    EXPECT_TRUE(vec[1] == Vector2f(9, 10) || vec[1] == Vector2f(8, 10));
}

TEST(Weapon, whenShootsUpWeaponOccupiesTheTwoBlocksUpwards)
{
    Harpoon harpoon;
    harpoon.shoot(Vector2f(10, 10), Direction::up);
    auto vec = harpoon.getOccupiedBlocks();
    EXPECT_TRUE(vec[0] == Vector2f(10, 9) || vec[0] == Vector2f(10, 8));
    EXPECT_TRUE(vec[1] == Vector2f(10, 9) || vec[1] == Vector2f(10, 8));
}

TEST(Weapon, whenShootsDownWeaponOccupiesTheTwoBlocksDownwards)
{
    Harpoon harpoon;
    harpoon.shoot(Vector2f(10, 10), Direction::down);
    auto vec = harpoon.getOccupiedBlocks();
    EXPECT_TRUE(vec[0] == Vector2f(10, 11) || vec[0] == Vector2f(10, 12));
    EXPECT_TRUE(vec[1] == Vector2f(10, 11) || vec[1] == Vector2f(10, 12));
}

TEST(Harpoon, whenHarpoonCreatedItDoesNotAutomaticallyShoot)
{
    Harpoon harpoon;
    EXPECT_FALSE(harpoon.isShooting());
}

TEST(Harpoon, whenHarpoonIsShotItShoots)
{
    Harpoon harpoon;
    harpoon.shoot(Vector2f(10, 10), Direction::right);
    EXPECT_TRUE(harpoon.isShooting());
}

TEST(Harpoon, everySecondCallToShootHarpoonIsRejected)
{
    Harpoon harpoon;
    harpoon.shoot(Vector2f(10, 10), Direction::right);
    EXPECT_TRUE(harpoon.isShooting());
    harpoon.shoot(Vector2f(10, 10), Direction::right);
    EXPECT_FALSE(harpoon.isShooting());
    harpoon.shoot(Vector2f(10, 10), Direction::right);
    EXPECT_TRUE(harpoon.isShooting());
    harpoon.shoot(Vector2f(10, 10), Direction::right);
    EXPECT_FALSE(harpoon.isShooting());
}

TEST(Harpoon, whenHarpoonIsWithdrawnItWillNoLongerBeShooting)
{
    Harpoon harpoon;
    harpoon.shoot(Vector2f(10, 10), Direction::right);
    EXPECT_TRUE(harpoon.isShooting());
    harpoon.withdrawHarpoon();
    EXPECT_FALSE(harpoon.isShooting());
}

TEST(Harpoon, whenHarpoonIsShotAndDugIsInBlockNextToHarpoonDugDies)
{
    Harpoon harpoon;
    Dug dug;
    dug.setStartPosition(Vector2f(10, 10));
    harpoon.shoot(Vector2f(9, 10), Direction::right);
    auto vec = harpoon.getOccupiedBlocks();
    for(auto point : vec) {
	dug.collisionCheck(point);
    }
    EXPECT_EQ(4, dug.getLives());
}

TEST(Harpoon, whenHarpoonIsShotAndDugIsOneBlockawayFromHarpoonDugDies)
{
    Harpoon harpoon;
    Dug dug;
    dug.setStartPosition(Vector2f(10, 10));
    harpoon.shoot(Vector2f(8, 10), Direction::right);
    auto vec = harpoon.getOccupiedBlocks();
    for(auto point : vec) {
	dug.collisionCheck(point);
    }
    EXPECT_EQ(4, dug.getLives());
}

TEST(Rock, whenRockIsCreatedItDoesNotAutomaticallyBeginFalling)
{
    Rock rock(Vector2f(10, 10));
    EXPECT_FALSE(rock.isFalling());
}

TEST(Rock, whenRockIsCreatedItCannotBeDestroyedImmeadiately)
{
    Rock rock(Vector2f(10, 10));
    EXPECT_FALSE(rock.canDestroyRock());
}

TEST(Rock, whenBlockUnderneathRockIsOpenedRockDoesNotAutomaticcallyBeginToFall)
{
    Rock rock(Vector2f(10, 10));
    rock.fallRoutine(true);
    EXPECT_FALSE(rock.isFalling());
}

TEST(Rock, whenBlockUnderneathRockIsOpenedRockOnlyBeginsToFallAfterNineGameCycles)
{
    Rock rock(Vector2f(10, 10));
    for(auto i = 0; i != 8; i++) {
	rock.fallRoutine(true);
    }
    EXPECT_FALSE(rock.isFalling());
    rock.fallRoutine(true);
    EXPECT_TRUE(rock.isFalling());
}

TEST(Rock, onceRockHasBegunToFallAndItHasNotYetHitTheBottomOfATunnelTheRockCannotBeDestroyed)
{
    Rock rock(Vector2f(10, 10));
    for(auto i = 0; i != 10; i++) {
	rock.fallRoutine(true);
    }
    EXPECT_FALSE(rock.canDestroyRock());
}

TEST(Rock, onceRockHasBegunToFallAndItThenHitsTheBottomOfATunnelTheRockCanBeDestroyed)
{
    Rock rock(Vector2f(10, 10));
    for(auto i = 0; i != 9; i++) {
	rock.fallRoutine(true);
    }
    rock.fallRoutine(false);
    EXPECT_TRUE(rock.canDestroyRock());
}

TEST(Rock, rocksYpositionChangesWhenItBeginsToFall)
{
    Rock rock(Vector2f(10, 10));
    for(auto i = 0; i != 9; i++) {
	rock.fallRoutine(true);
    }
    EXPECT_EQ(Vector2f(10, 11), rock.getPosition());
    rock.fallRoutine(true);
    EXPECT_EQ(Vector2f(10, 12), rock.getPosition());
}

TEST(Rock, rockWillNotFallBottomOfGrid)
{
    Rock rock(Vector2f(10, arrVars::ARRAYBREADTH - 2));
    for(auto i = 0; i != 9; i++) {
	rock.fallRoutine(true);
    }
    rock.fallRoutine(true);
    EXPECT_FALSE(rock.isFalling());
    EXPECT_TRUE(rock.canDestroyRock());
    EXPECT_EQ(Vector2f(10, arrVars::ARRAYBREADTH - 1), rock.getPosition());
}

TEST(Monster, MonsterByDefaultContructedToNotBeAGhost)
{
    Monster monster;
    EXPECT_FALSE(monster.isGhost());
}

TEST(Monster, ifMonsterAtRightEndOfHorizontalTunneltWillThenMoveToTheLeft)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(0, 0));
    Monster monster;
    monster.setStartPosition(Vector2f(19, 10));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(18, 10), monster.getPosition());
}

TEST(Monster, ifMonsterAtRightEndOfHorizontalTunneltWillNotMoveOutOfTunnelEvenIfDugIsInThatDirectionInAnotherTunnel)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(21, 10));
    Monster monster;
    monster.setStartPosition(Vector2f(19, 10));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(18, 10), monster.getPosition());
}

TEST(Monster, ifMonsterAtLeftEndOfHorizontalTunneltWillThenMoveToTheRight)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(0, 0));
    Monster monster;
    monster.setStartPosition(Vector2f(5, 10));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(6, 10), monster.getPosition());
}

TEST(Monster, ifMonsterAtLeftEndOfHorizontalTunneltWillNotMoveOutOfTunnelEvenIfDugIsInThatDirectionInAnotherTunnel)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(4, 10));
    Monster monster;
    monster.setStartPosition(Vector2f(5, 10));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(6, 10), monster.getPosition());
}

TEST(Monster, ifMonsterAtTopEndOfVerticalTunneltWillThenMoveDownwards)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(0, 0));
    Monster monster;
    monster.setStartPosition(Vector2f(52, 5));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 6), monster.getPosition());
}

TEST(Monster, ifMonsterAtTopEndOfVerticalTunneltWillNotMoveOutOfTunnelEvenIfDugIsInThatDirectionInAnotherTunnel)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(52, 4));
    Monster monster;
    monster.setStartPosition(Vector2f(52, 5));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 6), monster.getPosition());
}

TEST(Monster, ifMonsterAtBottomEndOfVerticalTunneltWillThenMoveUpwards)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(0, 0));
    Monster monster;
    monster.setStartPosition(Vector2f(52, 13));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 12), monster.getPosition());
}

TEST(Monster, ifMonsterAtBottomEndOfVertucalTunneltWillNotMoveOutOfTunnelEvenIfDugIsInThatDirectionInAnotherTunnel)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(52, 14));
    Monster monster;
    monster.setStartPosition(Vector2f(52, 13));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 12), monster.getPosition());
}


TEST(Monster, ifMonsterInMiddlefHorizontalTunneltWillContinueInAGivenDirectionDespiteDugsPosition)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(9, 10));
    Monster monster;
    monster.setStartPosition(Vector2f(10, 10));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(11, 10), monster.getPosition());
    direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(12, 10), monster.getPosition());
    direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(13, 10), monster.getPosition());
}

TEST(Monster, ifMonsterInMiddleVerticalTunneltWillContinueInAGivenDirectionDespiteDugsPosition)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(0,0 ));
    Monster monster;
    monster.setStartPosition(Vector2f(52, 10));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 9), monster.getPosition());
    direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 8), monster.getPosition());
    direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 7), monster.getPosition());
}

TEST(Monster, ifMonsterIsAtThreeWayForkWhichExtendsUpDownLeftMonsterMovesLeftIdFugInTunnelToTheLeft)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(48, 9));
    Monster monster;
    monster.setStartPosition(Vector2f(52, 9));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(51, 9), monster.getPosition());
}

TEST(Monster, ifMonsterIsAtThreeWayForkWhichExtendsUpDownLeftMonsterMovesUpTowardsDugIfDugInTheUpwardsTunnel)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(52, 6));
    Monster monster;
    monster.setStartPosition(Vector2f(52, 9));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 8), monster.getPosition());
}

TEST(Monster, ifMonsterIsAtThreeWayForkWhichExtendsUpDownLeftMonsterMovesDownTowardsDugIfDugInTunnelThAtExtendsDown)
{
    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(52, 13));
    Monster monster;
    monster.setStartPosition(Vector2f(52, 9));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 10), monster.getPosition());
}

/////////////////////////////////////////////

TEST(Monster, ifMonsterAtFourWayForkInATunnelDugMovesToTheRightIfDugIsInTunnelToTheRight)
{

    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(51, 9));
        dug.move(Direction::right);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
	dug.move(Direction::right);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
	dug.move(Direction::right);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
    Monster monster;
    monster.setStartPosition(Vector2f(52, 9));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(53, 9), monster.getPosition());
}

TEST(Monster, ifMonsterAtFourWayForkInATunnelDugMovesToTheLeftIfDugIsInTunnelToTheLeft)
{

    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(51, 9));
        dug.move(Direction::right);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
	dug.move(Direction::left);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
	dug.move(Direction::left);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
    Monster monster;
    monster.setStartPosition(Vector2f(52, 9));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(51, 9), monster.getPosition());
}

TEST(Monster, ifMonsterAtFourWayForkInATunnelDugMovesUpIfDugIsInTunnelUpwards)
{

    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(51, 9));
        dug.move(Direction::right);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
	dug.move(Direction::left);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
	dug.move(Direction::up);
	dug.move(Direction::up);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
    Monster monster;
    monster.setStartPosition(Vector2f(52, 9));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 8), monster.getPosition());
}

TEST(Monster, ifMonsterAtFourWayForkInATunnelDugMovesDownIfDugIsInTunnelDownwards)
{

    BlockArray array;
    Dug dug;
    dug.setStartPosition(Vector2f(51, 9));
        dug.move(Direction::right);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
	dug.move(Direction::left);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
	dug.move(Direction::down);
	dug.move(Direction::down);
	array.getBlock(dug.getPosition()).getBorder().updateBorder(dug.getDirection());
    Monster monster;
    monster.setStartPosition(Vector2f(52, 9));
    auto direcVec = array.getAdjacentOpen(monster.getPosition());
    monster.movement(direcVec, dug.getPosition(), array.getBlock(monster.getPosition()).isEmpty());
    EXPECT_EQ(Vector2f(52, 10), monster.getPosition());
}

TEST(Monster, monsterBecomesAGhostSometimes)
{
    Monster monster;
    auto ghostCount = 0;
    std::vector<Direction> emptyVec;
    for(auto i = 0; i != 1000; i++) {
	monster.movement(emptyVec, Vector2f(0, 0), true);
	if(monster.isGhost())
	    ghostCount++;
    }
    EXPECT_TRUE(ghostCount > 0);
}

TEST(Monster, onceMonsterBecomesAGhostItRemainsInGhostStateUntilItIntersectsATunnel)
{
    BlockArray array;
    Monster monster;
    monster.setStartPosition(Vector2f(arrVars::ARRAYLENGTH - 2, arrVars::ARRAYBREADTH - 2));
    std::vector<Direction> emptyVec;
    while(!monster.isGhost()) {
	monster.movement(emptyVec, Vector2f(0, 0), array.getBlock(monster.getPosition()).isEmpty());
    }
    while(monster.isGhost()) {
	monster.movement(emptyVec, Vector2f(0, 0), array.getBlock(monster.getPosition()).isEmpty());
    }
    EXPECT_TRUE(array.getBlock(monster.getPosition()).isEmpty());
}

TEST(Monster, monsterInGhostFormWillChaseDug)
{
    Dug dug;
    Monster monster;
    dug.setStartPosition(Vector2f(10, 10));
    monster.setStartPosition(Vector2f(100, 100));
    std::vector<Direction> emptyVec;
    while(!monster.isGhost()) {
	monster.movement(emptyVec, dug.getPosition(), false);
    }
    for(auto i = 0; i < 1000; i++) {
	monster.movement(emptyVec, dug.getPosition(), false);
    }
    EXPECT_EQ(dug.getPosition(), monster.getPosition());
}