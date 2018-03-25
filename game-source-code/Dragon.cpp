#include "Dragon.h"
#include <cstdlib>

Dragon::Dragon()
{
    _spitCount = 5;
    _isSpitting = false;
}

void Dragon::armDragon()
{
    // 1 in 10 chance of the Dragon spitting fire. OR if he was spitting in the previous game cycle and it has been less
    // than 5 consecutive game cycles he continues to spit
    if(rand() % 12 == 5 || _isSpitting) {
	_fire.shoot(_arrayPos, _direction);
	_isSpitting = true;
	_spitCount--;

	// If he has now been spitting for the past 5 game cycles he will then withdraw his fire and the _spitCount is
	// reset
	if(_spitCount == 0) {
	    _isSpitting = false;
	    _spitCount = 5;
	}
    }
    // If he is not spitting then his fire dissapears from screen
    else {
	_fire.retract();
    }
}

Fire& Dragon::getFire()
{
    return _fire;
}

bool Dragon::isSpitting() const
{
    if(_isSpitting)
	return true;
    else
	return false;
}