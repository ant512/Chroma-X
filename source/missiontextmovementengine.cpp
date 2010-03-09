#include "missiontextmovementengine.h"

MissionTextMovementEngine::MissionTextMovementEngine() {
    _ySpeed = -768;
    _yAcceleration = 8;
}

MissionTextMovementEngine::~MissionTextMovementEngine() {
}

bool MissionTextMovementEngine::move() {

    // Get sprite co-ordinates
    Sint32 y = _sprite->getShiftedY();

    Sint32 shiftedY = 0;

    // Accelerate
    _ySpeed += _yAcceleration;

    // Update co-ordinates
    y += _ySpeed;

    // Get shifted versions of co-ordinates for boundary checking
    shiftedY = y >> 8;

    if (_ySpeed > 0) _yAcceleration = -_yAcceleration;

    // Sprite is dead if it is off-screen
    if (shiftedY > PLAYFIELD_HEIGHT) {
        _sprite->kill();
    } else if (shiftedY < 0 - (Sint32)_sprite->getHeight()) {
        _sprite->kill();
    }

    // Update sprite
    _sprite->setShiftedY(y);

    return true;
}
