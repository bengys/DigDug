#include "Rock.h"
#include "global.h"

Rock::Rock(sf::Vector2f vec)
{
    _arrayPos = vec;
    _fallDelay = 8;
    _isFalling = false;
    _canDestroyRock = false;
}



void Rock::fallRoutine(bool isOpenUnderneath)
{
    if(isOpenUnderneath && (_fallDelay <= 0) && _arrayPos.y != arrVars::ARRAYBREADTH -1  ) {
        _arrayPos.y += 1;
        _isFalling = true;
        return;
    }

    if(isOpenUnderneath) {
        _fallDelay--;
    }

    // rock has been unsettled and fallen, but now hit the bottom of a tunnel
    if((_isFalling && !isOpenUnderneath) || _arrayPos.y == arrVars::ARRAYBREADTH - 1 ) {
        _canDestroyRock = true;
		_isFalling = false;
    }
}

bool Rock::isFalling() const
{
    if(_isFalling)
        return true;
    else
        return false;
}

bool Rock::canDestroyRock() const
{
    if(_canDestroyRock)
        return true;
    else
        return false;
}

