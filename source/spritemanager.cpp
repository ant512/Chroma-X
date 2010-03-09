#include "spritemanager.h"
#include "gamesprite.h"

SpriteManager::SpriteManager() {
}

SpriteManager::~SpriteManager() {
    clear();
}

void SpriteManager::add(GameSprite* sprite) {
    _sprites.push_back(sprite);
}

void SpriteManager::run() {
    for (Uint32 i = 0; i < _sprites.size(); i++) {
        _sprites[i]->run();

        // Has the sprite expired?
        if (_sprites[i]->isDead()) {

            // Delete sprite enemy from list
            delete _sprites[i];
            _sprites.erase(_sprites.begin() + i);
            i--;
        }
    }
}

void SpriteManager::clear() {
    for (Uint32 i = 0; i < _sprites.size(); i++) {
        delete _sprites[i];
    }

    _sprites.clear();
}
