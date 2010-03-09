#include "blades.h"

Blades::Blades() {
    // Set up renderer
    setRenderEngine(new AnimationRenderEngine());

    // Set up animation
    Animation* anim = ((AnimationRenderEngine*)_renderEngine)->getAnimation();

    anim->addFrame(BitmapServer::BITMAP_BLADES_1, 0);
    anim->addFrame(BitmapServer::BITMAP_BLADES_2, 0);
    anim->addFrame(BitmapServer::BITMAP_BLADES_3, 0);
    anim->addFrame(BitmapServer::BITMAP_BLADES_4, 0);

    anim->setSpeed(1);
    anim->play();
}

Blades::~Blades() {
}
