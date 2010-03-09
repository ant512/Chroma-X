#include "cloudmovementengine.h"

CloudMovementEngine::CloudMovementEngine(Sint32 xSpeed, Sint32 ySpeed, Sint32 xAcceleration, Sint32 yAcceleration) : BasicMovementEngine(xSpeed, ySpeed, xAcceleration, yAcceleration) {
}

CloudMovementEngine::~CloudMovementEngine() {
}

void CloudMovementEngine::checkBoundaries() {

    // Get shifted versions of co-ordinates for boundary checking
    Sint32 x = _sprite->getX();
    Sint32 y = _sprite->getY();

    // Sprite is dead if it is off-screen
    if (y > PLAYFIELD_HEIGHT + (Sint32)_sprite->getHeight()) {
        _sprite->kill();
    } else if (y < 0 - (Sint32)(_sprite->getHeight() << 1)) {
        _sprite->kill();
    } else if (x > PLAYFIELD_X + PLAYFIELD_WIDTH) {
        _sprite->kill();
    } else if (x < (Sint32)(PLAYFIELD_X - _sprite->getWidth())) {
        _sprite->kill();
    }
}
