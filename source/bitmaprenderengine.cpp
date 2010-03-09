#include "bitmaprenderengine.h"

BitmapRenderEngine::BitmapRenderEngine() {
    _surface = NULL;
}

BitmapRenderEngine::~BitmapRenderEngine() {
}

void BitmapRenderEngine::setBitmap(BitmapServer::BitmapType type) {
    _surface = BitmapServer::getBitmap(type);
}

bool BitmapRenderEngine::draw() {

    if (_sprite != NULL) {
        if (_surface != NULL) {
            // Draw sprite
            SDL_Rect rect;
            rect.x = _sprite->getX();
            rect.y = _sprite->getY();
            rect.w = _surface->w;
            rect.h = _surface->h;

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

                SDL_BlitSurface(_surface, &clip, SDLTools::getScreen(), &rect);
            } else {

                // Draw unclipped sprite
                SDL_BlitSurface(_surface, NULL, SDLTools::getScreen(), &rect);
            }


            return true;
        }
    }

    return false;
}

const Uint32 BitmapRenderEngine::getWidth() const {
    return _surface->w;
}

const Uint32 BitmapRenderEngine::getHeight() const {
    return _surface->h;
}

SDL_Surface* BitmapRenderEngine::getSurface() {
    return _surface;
}
