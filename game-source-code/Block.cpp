#include "global.h"
#include "Block.h"

int Block::xCount = 0;
int Block::yCount = 0;

Block::Block()
    : _type{ BlockType::solid }
{
    setArrayPos();
    _border.setArrayPos(_arrayPos);
    _isEmpty = false;
}

bool Block::isEmpty() const
{
    if(_isEmpty)
	return true;
    else
	return false;
}

void Block::changeTypetoEmpty()
{
    if(!_isEmpty) {
	_type = BlockType::empty;
	_isEmpty = true;
    }
}

void Block::setArrayPos()
{
    _arrayPos.x = xCount;
    _arrayPos.y = yCount;
    yCount++;
    if(yCount == arrVars::ARRAYBREADTH) {
	xCount++;
	yCount = 0;
    }
}

Border& Block::getBorder()
{
    return _border;
}
