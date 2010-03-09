#include "basicmovementengine.h"

BasicMovementEngine::BasicMovementEngine(Sint32 xSpeed, Sint32 ySpeed, Sint32 xAcceleration, Sint32 yAcceleration) {
    _xSpeed = xSpeed;
    _ySpeed = ySpeed;
    _xAcceleration = xAcceleration;
    _yAcceleration = yAcceleration;
}

BasicMovementEngine::~BasicMovementEngine() {
}

bool BasicMovementEngine::move() {

    // Get sprite co-ordinates
    Sint32 x = _sprite->getShiftedX();
    Sint32 y = _sprite->getShiftedY();

    // Accelerate
    _xSpeed += _xAcceleration;
    _ySpeed += _yAcceleration;

    // Update co-ordinates
    x += _xSpeed;
    y += _ySpeed;

    // Update sprite
    _sprite->setShiftedX(x);
    _sprite->setShiftedY(y);

    // Kill sprite if out of bounds
    checkBoundaries();

    return true;
}

void BasicMovementEngine::checkBoundaries() {

    // Get shifted versions of co-ordinates for boundary checking
    Sint32 x = _sprite->getX();
    Sint32 y = _sprite->getY();

    // Sprite is dead if it is off-screen
    if (y > PLAYFIELD_HEIGHT) {
        _sprite->kill();
    } else if (y < 0 - (Sint32)_sprite->getHeight()) {
        _sprite->kill();
    } else if (x > PLAYFIELD_X + PLAYFIELD_WIDTH) {
        _sprite->kill();
    } else if (x < (Sint32)(PLAYFIELD_X - _sprite->getWidth())) {
        _sprite->kill();
    }
}

void BasicMovementEngine::setYSpeed(Sint32 ySpeed) {
    _ySpeed = ySpeed;
}
