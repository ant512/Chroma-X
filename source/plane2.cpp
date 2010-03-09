#include "plane2.h"

Plane2::Plane2() {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());
    ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_PLANE2_CENTRE);

    _speed = 256;
    _killScore = 500;
    _shieldStrength = 4;

    // Set up movement
    setMovementEngine(new BasicMovementEngine(0, _speed, 0, 0));
}

Plane2::~Plane2() {
}

bool Plane2::run() {
    Enemy::run();

    Game::getParticleManager()->createSmokeTrail((_x >> 8) + (getWidth() / 2), _y >> 8, 0 >> 8, _speed >> 8);

    return true;
}
