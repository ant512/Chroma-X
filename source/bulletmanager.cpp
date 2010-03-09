#include "bulletmanager.h"
#include "bulletbase.h"
#include "gamesprite.h"

BulletManager::BulletManager() {
}

BulletManager::~BulletManager() {
    for (Uint32 i = 0; i < _bullets.size(); i++) {
        delete _bullets[i];
    }

    _bullets.clear();
}

void BulletManager::add(BulletBase* bullet) {
    _bullets.push_back(bullet);
}

void BulletManager::run() {
    for (Uint32 i = 0; i < _bullets.size(); i++) {
        _bullets[i]->run();

        // Has the bullet expired?
        if (_bullets[i]->isDead()) {

            // Delete dead _bullet from list
            delete _bullets[i];
            _bullets.erase(_bullets.begin() + i);
            i--;
        }
    }
}

Sint32 BulletManager::checkCollision(GameSprite* sprite) {

    // Loop through all bullets checking for a collision
    for (Uint32 i = 0; i < _bullets.size(); i++) {
        if (!_bullets[i]->isDead()) {
            if (sprite->checkCollision(_bullets[i])) {

                // Collision has occurred - kill the bullet
                _bullets[i]->kill();

                // Play a sound
                SoundPlayer::play(SoundPlayer::SOUND_CLANK_1);

                // Return the damage inflicted by the bullet
                return _bullets[i]->getDamage();
            }
        }
    }

    // No collision
    return -1;
}
