#include "spritebase.h"

SpriteBase::SpriteBase() {
    _x = 0;
    _y = 0;
    _width = 0;
    _height = 0;
    _isDead = false;
}

SpriteBase::~SpriteBase() {
}

const Sint32 SpriteBase::getX() const {
    return _x >> 8;
}

const Sint32 SpriteBase::getY() const {
    return _y >> 8;
}

const Sint32 SpriteBase::getShiftedX() const {
    return _x;
}

const Sint32 SpriteBase::getShiftedY() const {
    return _y;
}

const bool SpriteBase::isDead() const {
    return _isDead;
}

const Uint32 SpriteBase::getWidth() const {
    return _width;
}

const Uint32 SpriteBase::getHeight() const {
    return _height;
}

void SpriteBase::setX(Sint32 x) {
    _x = x << 8;
}

void SpriteBase::setY(Sint32 y) {
    _y = y << 8;
}

void SpriteBase::setShiftedX(Sint32 x) {
    _x = x;
}

void SpriteBase::setShiftedY(Sint32 y) {
    _y = y;
}

bool SpriteBase::run() {
    return !_isDead;
}

void SpriteBase::kill() {
    _isDead = true;
}
