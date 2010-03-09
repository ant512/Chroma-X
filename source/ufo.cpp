#include "ufo.h"

UFO::UFO() {
    // Set up renderer
    setRenderEngine(new AnimationRenderEngine());

    // Set up animation
    Animation* anim = ((AnimationRenderEngine*)_renderEngine)->getAnimation();

    anim->addFrame(BitmapServer::BITMAP_UFO_1, 0);
    anim->addFrame(BitmapServer::BITMAP_UFO_2, 0);
    anim->addFrame(BitmapServer::BITMAP_UFO_3, 0);
    anim->addFrame(BitmapServer::BITMAP_UFO_4, 0);
    anim->addFrame(BitmapServer::BITMAP_UFO_5, 0);
    anim->addFrame(BitmapServer::BITMAP_UFO_6, 0);
    anim->addFrame(BitmapServer::BITMAP_UFO_7, 0);
    anim->addFrame(BitmapServer::BITMAP_UFO_8, 0);

    anim->setSpeed(1);
    anim->play();

    // Set up movement
    //setMovementEngine(new PlayerMovementEngine());

    // Set up firing mechanism
    setCannonEngine(new RadialCannonEngine());

    _killScore = 1000;
    _shieldStrength = 10;
    _dropPowerup = true;
}

UFO::~UFO() {
}
