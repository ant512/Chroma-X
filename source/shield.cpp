#include "shield.h"

Shield::Shield() {
    // Set up renderer
    setRenderEngine(new AnimationRenderEngine());

    // Set up animation
    Animation* anim = ((AnimationRenderEngine*)_renderEngine)->getAnimation();

    anim->addFrame(BitmapServer::BITMAP_SHIELD_1, 0);
    anim->addFrame(BitmapServer::BITMAP_SHIELD_2, 0);
    anim->addFrame(BitmapServer::BITMAP_SHIELD_3, 0);
    anim->addFrame(BitmapServer::BITMAP_SHIELD_4, 0);

    anim->setSpeed(8);
    anim->play();
}

Shield::~Shield() {
}
