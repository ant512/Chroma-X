#include "renderengine.h"

RenderEngine::RenderEngine() {
	_sprite = NULL;
	_clipped = true;
}

RenderEngine::~RenderEngine() {
}

bool RenderEngine::setSprite(SpriteBase* sprite) {

	// Only allow sprite to be re-assigned if it has not yet been set
	if (_sprite == NULL) {
		_sprite = sprite;

		return true;
	}

	return false;
}

void RenderEngine::setClipping(const bool clipping) {
    _clipped = clipping;
}
