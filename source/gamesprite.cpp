#include "gamesprite.h"

GameSprite::GameSprite() {
	_movementEngine = NULL;
	_cannonEngine = NULL;
	_renderEngine = NULL;
}

GameSprite::~GameSprite() {
	if (_movementEngine != NULL) {
		delete _movementEngine;
	}

	if (_cannonEngine != NULL) {
		delete _cannonEngine;
	}

	if (_renderEngine != NULL) {
	    delete _renderEngine;
	}
}

bool GameSprite::run() {

	// Move the sprite
	if (_movementEngine != NULL) {
		_movementEngine->move();
	}

	// Shooting logic
	if (_cannonEngine != NULL) {
		_cannonEngine->shoot();
	}

	// Drawing
	if (_renderEngine != NULL) {
	    _renderEngine->draw();
	}

	return true;
}

bool GameSprite::setMovementEngine(MovementEngine* movementEngine) {

	// Update movement engine's sprite pointer
	if (movementEngine->setSprite(this)) {

		// Delete existing engine
		if (_movementEngine != NULL) {
			delete _movementEngine;
		}

		// Update movement engine pointer
		_movementEngine = movementEngine;

		return true;
	}

	// Cannot update movement engine's sprite pointer
	return false;
}

bool GameSprite::setCannonEngine(CannonEngine* cannonEngine) {

	// Update cannon engine's sprite pointer
	if (cannonEngine->setSprite(this)) {

		// Delete existing engine
		if (_cannonEngine != NULL) {
			delete _cannonEngine;
		}

		// Update cannon engine pointer
		_cannonEngine = cannonEngine;

		return true;
	}

	// Cannot update cannon engine's sprite pointer
	return false;
}

bool GameSprite::setRenderEngine(RenderEngine* renderEngine) {

	// Update render engine's sprite pointer
	if (renderEngine->setSprite(this)) {

		// Delete existing engine
		if (_renderEngine != NULL) {
			delete _renderEngine;
		}

		// Update render engine pointer
		_renderEngine = renderEngine;

		return true;
	}

	// Cannot update render engine's sprite pointer
	return false;
}

MovementEngine* GameSprite::getMovementEngine() {
    return _movementEngine;
}

CannonEngine* GameSprite::getCannonEngine() {
    return _cannonEngine;
}

RenderEngine* GameSprite::getRenderEngine() {
    return _renderEngine;
}

bool GameSprite::checkCollision(GameSprite* sprite) {

    // Check bounding box collisions first for speed
    if (checkBoundingCollision(sprite)) {
        // Check pixel collisions for accuracy
        return checkPixelCollision(sprite);
    }

    return false;
}

bool GameSprite::checkBoundingCollision(GameSprite* sprite) {

    // Extract data from both sprites
    Sint32 meX = getX();
    Sint32 meY = getY();
    Sint32 meWidth = (Sint32)getWidth();
    Sint32 meHeight = (Sint32)getHeight();
    Sint32 himX = sprite->getX();
    Sint32 himY = sprite->getY();
    Sint32 himWidth = (Sint32)sprite->getWidth();
    Sint32 himHeight = (Sint32)sprite->getHeight();

    // Compare non-matching possibilities to reduce amount
    // of checks performed.
    if (himX + himWidth < meX) return false;
    if (himX > meX + meWidth) return false;
    if (himY + himHeight < meY) return false;
    if (himY > meY + meHeight) return false;

    // Collision found
    return true;
}

bool GameSprite::checkPixelCollision(GameSprite* sprite) {

    // Extract data from both sprites
    Sint32 meX1 = getX();
    Sint32 meY1 = getY();
    Sint32 meX2 = meX1 + (Sint32)getWidth() - 1;
    Sint32 meY2 = meY1 + (Sint32)getHeight() - 1;
    Sint32 himX1 = sprite->getX();
    Sint32 himY1 = sprite->getY();
    Sint32 himX2 = himX1 + (Sint32)sprite->getWidth() - 1;
    Sint32 himY2 = himY1 + (Sint32)sprite->getHeight() - 1;

    // Perform bounding box check.
    // Compare non-matching possibilities to reduce amount
    // of checks performed.
    if (himX2 < meX1) return false;
    if (himX1 > meX2) return false;
    if (himY2 < meY1) return false;
    if (himY1 > meY2) return false;

    // Ensure we have render engines for both sprites
    if (_renderEngine == NULL) return false;
    if (sprite->getRenderEngine() == NULL) return false;

    // Locate the bounding box co-ordinates
    Sint32 x1 = himX1 > meX1 ? himX1 : meX1;
    Sint32 y1 = himY1 > meY1 ? himY1 : meY1;
    Sint32 x2 = himX2 < meX2 ? himX2 : meX2;
    Sint32 y2 = himY2 < meY2 ? himY2 : meY2;

    // Get surfaces to compare
    SDL_Surface* meSurface = _renderEngine->getSurface();
    SDL_Surface* himSurface = sprite->getRenderEngine()->getSurface();

    // Ensure we have surfaces
    if (meSurface == NULL) return false;
    if (himSurface == NULL) return false;

    // Scan for overlapping non-transparent pixels
    for (Sint32 x = x1; x <= x2; x++) {
        for (Sint32 y = y1; y <= y2; y++) {
            if (!SDLTools::isPixelTransparent(himSurface, x - himX1, y - himY1) &&
                !SDLTools::isPixelTransparent(meSurface, x - meX1, y - meY1)) {
                return true;
            }
        }
    }

    return false;
}


const Uint32 GameSprite::getWidth() const {
    if (_renderEngine != NULL) {
        return _renderEngine->getWidth();
    } else {
        return _width;
    }
}

const Uint32 GameSprite::getHeight() const {
    if (_renderEngine != NULL) {
        return _renderEngine->getHeight();
    } else {
        return _height;
    }
}
