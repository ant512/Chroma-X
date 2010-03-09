#include "rocket.h"

Rocket::Rocket() {
    // Set up renderer
    setRenderEngine(new AnimationRenderEngine());

    // Set up animation
    Animation* anim = ((AnimationRenderEngine*)_renderEngine)->getAnimation();

    anim->addFrame(BitmapServer::BITMAP_ROCKET_1, 0);
    anim->addFrame(BitmapServer::BITMAP_ROCKET_2, 0);
    anim->addFrame(BitmapServer::BITMAP_ROCKET_3, 0);
    anim->addFrame(BitmapServer::BITMAP_ROCKET_4, 0);
    anim->addFrame(BitmapServer::BITMAP_ROCKET_5, 0);
    anim->addFrame(BitmapServer::BITMAP_ROCKET_6, 0);

    anim->setSpeed(2);
    anim->play();

    _speed = 256;
    _killScore = 100;
    _shieldStrength = 2;

    // Set up movement
    setMovementEngine(new BasicMovementEngine(0, _speed, 0, 0));
}

Rocket::~Rocket() {
}

bool Rocket::run() {
    Enemy::run();

    Game::getParticleManager()->createSmokeTrail((_x >> 8) + (getWidth() / 2), _y >> 8, 0 >> 8, _speed >> 8);

    return true;
}
