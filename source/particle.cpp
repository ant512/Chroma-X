#include "particle.h"

Particle::Particle(Uint32 colour, Sint32 x, Sint32 y, Sint32 speedX, Sint32 speedY, Sint32 accelerationX, Sint32 accelerationY, Sint32 speedLimitX, Sint32 speedLimitY, Uint32 lifeTime) {

    // Store all values bitshifted left 8 places, so we can use the low byte
    // as a fixed-point fraction.
    // All values should be passed in pre-bitshifted except for x and y.
    _x = x << 8;
    _y = y << 8;
    _speedX = speedX;
    _speedY = speedY;
    _accelerationX = accelerationX;
    _accelerationY = accelerationY;
    _speedLimitX = speedLimitX;
    _speedLimitY = speedLimitY;
    _colour = colour;
    _lifeTime = lifeTime;
    _width = 2;
    _height = 2;

    _timer = 0;
    _isDead = false;
}

Particle::~Particle() {
}

bool Particle::run() {
    // Move particle
    _x += _speedX;
    _y += _speedY;

    // Accelerate
    _speedX += _accelerationX;
    _speedY += _accelerationY;

    // Increase timer
    if (_lifeTime > 0) {
        _timer++;
    }

    // Limit speed
    if ((_accelerationX > 0) && (_speedX > _speedLimitX)) {
        _isDead = true;
    }

    if ((_accelerationX < 0) && (_speedX < _speedLimitX)) {
        _isDead = true;
    }

    if ((_accelerationY > 0) && (_speedY > _speedLimitY)) {
        _isDead = true;
    }

    if ((_accelerationY < 0) && (_speedY < _speedLimitY)) {
        _isDead = true;
    }

    // Limit position
    if ((_x < PLAYFIELD_X << 8) || (_x + (_width << 8) > (PLAYFIELD_X + PLAYFIELD_WIDTH) << 8)) {
        _isDead = true;
    }

    if ((_y < PLAYFIELD_Y << 8) || (_y + (_height << 8) > (PLAYFIELD_Y + PLAYFIELD_HEIGHT) << 8)) {
        _isDead = true;
    }

    // Limit lifetime
    if ((_timer > _lifeTime) && (_lifeTime > 0)) {
        _isDead = true;
    }

    // Draw
    if (!_isDead) {
        draw();
    }

    return !_isDead;
}

const void Particle::draw() const {
    //SDLTools::putPixel(_x >> 8, _y >> 8, _colour);
    SDL_Rect rect;
    rect.x = _x >> 8;
    rect.y = _y >> 8;
    rect.w = _width;
    rect.h = _height;
    SDL_FillRect(SDLTools::getScreen(), &rect, _colour);
}

const Sint32 Particle::getX() const {
    return _x >> 8;
}

const Sint32 Particle::getY() const {
    return _y >> 8;
}

const Sint32 Particle::getSpeedX() const {
    return _speedX;
}

const Sint32 Particle::getSpeedY() const {
    return _speedY;
}

const Sint32 Particle::getAccelerationX() const {
    return _accelerationX;
}

const Sint32 Particle::getAccelerationY() const {
    return _accelerationY;
}

const Sint32 Particle::getSpeedLimitX() const {
    return _speedLimitX;
}

const Sint32 Particle::getSpeedLimitY() const {
    return _speedLimitY;
}

const Uint32 Particle::getLifeTime() const {
    return _lifeTime;
}

const Uint32 Particle::getTimer() const {
    return _timer;
}

const bool Particle::isDead() const {
    return _isDead;
}

const Uint32 Particle::getColour() const {
    return _colour;
}

void Particle::setX(Sint32 x) {
    _x = x << 8;
}

void Particle::setY(Sint32 y) {
    _y = y << 8;
}

void Particle::setSpeedX(Sint32 speedX) {
    _speedX = speedX;
}

void Particle::setSpeedY(Sint32 speedY) {
    _speedY = speedY;
}

void Particle::setAccelerationX(Sint32 accelerationX) {
    _accelerationX = accelerationX;
}

void Particle::setAccelerationY(Sint32 accelerationY) {
    _accelerationY = accelerationY;
}

void Particle::setSpeedLimitX(Sint32 speedLimitX) {
    _speedLimitX = speedLimitX;
}

void Particle::setSpeedLimitY(Sint32 speedLimitY) {
    _speedLimitY = speedLimitY;
}

void Particle::setLifeTime(Uint32 lifeTime) {
    _lifeTime = lifeTime;
}

void Particle::setTimer(Uint32 timer) {
    _timer = timer;
}

void Particle::setDead(bool isDead) {
    _isDead = isDead;
}

void Particle::setColour(Uint32 colour) {
    _colour = colour;
}
