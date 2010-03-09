#include "plane1.h"

Plane1::Plane1() {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());
    ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_PLANE1_CENTRE);

    _speed = 256;
    _killScore = 500;
    _shieldStrength = 4;

    // Set up movement
    //setMovementEngine(new BasicMovementEngine(0, _speed, 0, 0));
    setMovementEngine(new LeftRightCurveMovementEngine());
}

Plane1::~Plane1() {
}

bool Plane1::run() {
    Enemy::run();

    // Handle tilt bitmaps
    Sint32 speed = _movementEngine->getXSpeed();
    if (speed > 2) {
        ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_PLANE1_TILT_RIGHT);
    } else if (speed < -2) {
        ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_PLANE1_TILT_LEFT);
    } else {
        ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_PLANE1_CENTRE);
    }

    Game::getParticleManager()->createSmokeTrail((_x >> 8) + (getWidth() / 2), _y >> 8, 0 >> 8, _speed >> 8);

    return true;
}
