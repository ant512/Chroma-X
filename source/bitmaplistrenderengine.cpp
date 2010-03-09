#include "bitmaplistrenderengine.h"

BitmapListRenderEngine::BitmapListRenderEngine() {
    _currentSurface = 0;
}

BitmapListRenderEngine::~BitmapListRenderEngine() {
    _surfaces.clear();
}

void BitmapListRenderEngine::setCurrentSurfaceIndex(Uint32 surfaceIndex) {
    if (surfaceIndex < _surfaces.size()) {
        _currentSurface = surfaceIndex;
    }
}

const Uint32 BitmapListRenderEngine::getCurrentSurfaceIndex() const {
    return _currentSurface;
}

void BitmapListRenderEngine::addBitmap(BitmapServer::BitmapType type) {

    // Add surface to vector
    _surfaces.push_back(BitmapServer::getBitmap(type));
}

bool BitmapListRenderEngine::draw() {

    if (_sprite != NULL) {
        if (_surfaces.size() > 0) {
            // Draw sprite
            SDL_Rect rect;
            rect.x = _sprite->getX();
            rect.y = _sprite->getY();

            SDL_BlitSurface(_surfaces[_currentSurface], NULL, SDLTools::getScreen(), &rect);

            return true;
        }
    }

    return false;
}

const Uint32 BitmapListRenderEngine::getCurrentWidth() const {
    return _surfaces[_currentSurface]->w;
}

const Uint32 BitmapListRenderEngine::getCurrentHeight() const {
    return _surfaces[_currentSurface]->h;
}

SDL_Surface* BitmapListRenderEngine::getSurface() {
    return _surfaces[_currentSurface];
}
