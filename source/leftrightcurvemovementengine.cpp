#include "leftrightcurvemovementengine.h"
#include "mathtools.h"

LeftRightCurveMovementEngine::LeftRightCurveMovementEngine() {
    _xSpeed = 0;
    _ySpeed = 256;
    _maxXAcceleration = 5;
    _xAcceleration = _maxXAcceleration;
    _yAcceleration = 0;
}

LeftRightCurveMovementEngine::~LeftRightCurveMovementEngine() {
}

bool LeftRightCurveMovementEngine::move() {

    // Get sprite co-ordinates
    Sint32 x = _sprite->getShiftedX();
    Sint32 y = _sprite->getShiftedY();
    Sint32 newX = 0;

    Sint32 shiftedX = 0;
    Sint32 shiftedY = 0;

    // Update y co-ordinate
    y += _ySpeed;

    // Get shifted versions of co-ordinates for boundary checking
    shiftedY = y >> 8;

    // Calculate x values
    newX = (160 << 8) + ((MathTools::sin(shiftedY << 1)) << 6);

    // Record x speed
    _xSpeed = newX - x;

    // Update x co-ord
    x = newX;
    shiftedX = x >> 8;


    // Sprite is dead if it is off-screen
    if (shiftedY > PLAYFIELD_HEIGHT) {
        _sprite->kill();
    } else if (shiftedY < 0 - (Sint32)_sprite->getHeight()) {
        _sprite->kill();
    } else if (shiftedX > PLAYFIELD_X + PLAYFIELD_WIDTH) {
        _sprite->kill();
    } else if (shiftedX < (Sint32)(PLAYFIELD_X - _sprite->getWidth())) {
        _sprite->kill();
    }

    // Update sprite
    _sprite->setShiftedX(x);
    _sprite->setShiftedY(y);

    return true;
}
