#include "cannonengine.h"

CannonEngine::CannonEngine() {
	_sprite = NULL;
}

CannonEngine::~CannonEngine() {
}

bool CannonEngine::setSprite(SpriteBase* sprite) {

	// Only allow sprite to be re-assigned if it has not yet been set
	if (_sprite == NULL) {
		_sprite = sprite;

		return true;
	}

	return false;
}
