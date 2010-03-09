#include "movementengine.h"

MovementEngine::MovementEngine() {
	_sprite = NULL;
    _xSpeed = 0;
    _ySpeed = 0;
    _xAcceleration = 0;
    _yAcceleration = 0;
}

MovementEngine::~MovementEngine() {
}

bool MovementEngine::setSprite(SpriteBase* sprite) {

	// Only allow sprite to be re-assigned if it has not yet been set
	if (_sprite == NULL) {
		_sprite = sprite;

		return true;
	}

	return false;
}

Sint32 MovementEngine::getXSpeed() {
    return _xSpeed;
}

Sint32 MovementEngine::getYSpeed() {
    return _ySpeed;
}

Sint32 MovementEngine::getXAcceleration() {
    return _xAcceleration;
}

Sint32 MovementEngine::getYAcceleration() {
    return _yAcceleration;
}

void MovementEngine::setXSpeed(Sint32 xSpeed) {
    _xSpeed = xSpeed;
}

void MovementEngine::setYSpeed(Sint32 ySpeed) {
    _ySpeed = ySpeed;
}

void MovementEngine::setXAcceleration(Sint32 xAcceleration) {
    _xAcceleration = xAcceleration;
}

void MovementEngine::setYAcceleration(Sint32 yAcceleration) {
    _yAcceleration = yAcceleration;
}
