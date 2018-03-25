#include "BlockArray.h"
#include "global.h"
#include "Block.h"

BlockArray::BlockArray()
{
    // Creates 2D vector by pushing 1D vectors(columns) into a 1D vector.
    for(int i = 0; i != arrVars::ARRAYLENGTH; ++i) {
	_arrCol.resize(arrVars::ARRAYBREADTH);
	_blockArr.push_back(_arrCol);
	_arrCol.clear();
    }
    setStartTunnels();
    _dugPastDirection = Direction::right;
    _previousBlockPos = sf::Vector2f(0, 0);
}

Block& BlockArray::getBlock(const sf::Vector2f& pos)
{
    auto x = pos.x;
    auto y = pos.y;
    if(x > arrVars::ARRAYLENGTH || y > arrVars::ARRAYBREADTH || x < 0 || y < 0) {
	throw BlockOutOfBounds();
    }
    return _blockArr[x][y];
}

void BlockArray::setStartTunnels()
{
    for(int i = 5; i != 20; i++) {
	_blockArr[i][10].changeTypetoEmpty();
	_blockArr[i][10].getBorder().updateBorder(Direction::right);
    }

    for(int j = 12; j != 19; j++) {
	_blockArr[40][j].changeTypetoEmpty();
	_blockArr[40][j].getBorder().updateBorder(Direction::down);
    }

    for(int i = 19; i != 28; i++) {
	_blockArr[i][14].changeTypetoEmpty();
	_blockArr[i][14].getBorder().updateBorder(Direction::right);
    }

    for(int i = 10; i != 50; i++) {
	_blockArr[i][0].changeTypetoEmpty();
	_blockArr[i][0].getBorder().updateBorder(Direction::right);
    }

    for(int j = 5; j != 14; j++) {
	_blockArr[52][j].changeTypetoEmpty();
	_blockArr[52][j].getBorder().updateBorder(Direction::down);
    }

    for(int i = 40; i != 53; i++) {
	_blockArr[i][9].changeTypetoEmpty();
	_blockArr[i][9].getBorder().updateBorder(Direction::right);
    }
}

std::vector<Direction> BlockArray::getAdjacentOpen(const sf::Vector2f& arrayPos) const
{
    // For each block that is adjacent to block at position arrayPos a check is performed in each of the 4 directions
    // surrounding the block. If the border of the block bordering in a given direction and the border of block in that
    // direction is open then that direction is pushed into the vector vec.

    // Left border
    std::vector<Direction> vec;
    if(arrayPos.x != 0 && _blockArr[arrayPos.x][arrayPos.y]._border.isOpenLeft &&
        (_blockArr[arrayPos.x - 1][arrayPos.y]._border.isOpenRight)) {
	vec.push_back(Direction::left);
    }

    // Right border
    if((arrayPos.x != arrVars::ARRAYLENGTH - 1) && _blockArr[arrayPos.x][arrayPos.y]._border.isOpenRight &&
        (_blockArr[arrayPos.x + 1][arrayPos.y]._border.isOpenLeft)) {
	vec.push_back(Direction::right);
    }

    // Top Border
    if(arrayPos.y != 0 && _blockArr[arrayPos.x][arrayPos.y]._border.isOpenTop &&
        (_blockArr[arrayPos.x][arrayPos.y - 1]._border.isOpenBottom)) {
	vec.push_back(Direction::up);
    }

    // Bottom Border
    if(arrayPos.y != arrVars::ARRAYBREADTH - 1 && _blockArr[arrayPos.x][arrayPos.y]._border.isOpenBottom &&
        (_blockArr[arrayPos.x][arrayPos.y + 1]._border.isOpenTop)) {
	vec.push_back(Direction::down);
    }

    return vec;
}

BlockArray::~BlockArray()
{
    Block::xCount = 0;
    Block::yCount = 0;
}

void BlockArray::eatBlock(const sf::Vector2f& dugPos, const Direction& dugDir)
{
    _blockArr[dugPos.x][dugPos.y].changeTypetoEmpty();
    _blockArr[_previousBlockPos.x][_previousBlockPos.y].getBorder().updatePreviousBorder(dugDir, _dugPastDirection);
    _blockArr[dugPos.x][dugPos.y].getBorder().updateBorder(dugDir);
    _dugPastDirection = dugDir;
    _previousBlockPos = dugPos;
}
