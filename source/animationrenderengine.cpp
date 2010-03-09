#include "animationrenderengine.h"

AnimationRenderEngine::AnimationRenderEngine() {
    _animation = new Animation(1, Animation::ANIMATION_LOOPTYPE_LOOP, 0);
}

AnimationRenderEngine::~AnimationRenderEngine() {
    delete _animation;
}

bool AnimationRenderEngine::draw() {
    if (_sprite != NULL) {
        if (_animation->getFrameCount() > 0) {

            // Draw sprite
            SDL_Rect rect;
            rect.x = _sprite->getX();
            rect.y = _sprite->getY();
            rect.w = _animation->getCurrentSurface()->w;
            rect.h = _animation->getCurrentSurface()->h;

            if (_clipped) {

                // Clip the sprite to the playfield
                SDL_Rect clip;
                clip.y = 0;
                clip.h = rect.h;

                // Clip left
                if (rect.x < PLAYFIELD_X) {
                    clip.x = PLAYFIELD_X - rect.x;
                    rect.x += clip.x;
                } else {
                    clip.x = 0;
                }

                // Clip right
                if ((rect.x + rect.w) > (PLAYFIELD_X + PLAYFIELD_WIDTH)) {
                    clip.w = rect.w - ((rect.x + rect.w) - (PLAYFIELD_X + PLAYFIELD_WIDTH));

                    // Prevent wraparound
                    if (clip.w > rect.w) clip.w = 0;
                } else {
                    clip.w = rect.w;
                }

                // Draw clipped sprite
                SDL_BlitSurface(_animation->getCurrentSurface(), &clip, SDLTools::getScreen(), &rect);
            } else {

                // Draw unclipped sprite
                SDL_BlitSurface(_animation->getCurrentSurface(), NULL, SDLTools::getScreen(), &rect);
            }

            // Run animation
            _animation->run();

            return true;
        }
    }

    return false;
}

const Uint32 AnimationRenderEngine::getWidth() const {
    return _animation->getCurrentSurface()->w;
}

const Uint32 AnimationRenderEngine::getHeight() const {
    return _animation->getCurrentSurface()->h;
}

Animation* AnimationRenderEngine::getAnimation() {
    return _animation;
}

SDL_Surface* AnimationRenderEngine::getSurface() {
     return _animation->getCurrentSurface();
}
