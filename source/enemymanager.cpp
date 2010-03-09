#include "enemymanager.h"
#include "enemy.h"
#include "rocket.h"
#include "ufo.h"
#include "plane1.h"
#include "plane2.h"
#include "gamesprite.h"

EnemyManager::EnemyManager() {
}

EnemyManager::~EnemyManager() {
    for (Uint32 i = 0; i < _enemies.size(); i++) {
        delete _enemies[i];
    }

    _enemies.clear();
}

void EnemyManager::add(Enemy* enemy) {
    _enemies.push_back(enemy);
}

void EnemyManager::run() {
    for (Uint32 i = 0; i < _enemies.size(); i++) {
        _enemies[i]->run();

        // Has the enemy expired?
        if (_enemies[i]->isDead()) {

            // Delete dead enemy from list
            delete _enemies[i];
            _enemies.erase(_enemies.begin() + i);
            i--;
        }
    }
}

bool EnemyManager::checkCollision(GameSprite* sprite) {

    // Loop through all enemies checking for a collision
    for (Uint32 i = 0; i < _enemies.size(); i++) {
        if (!_enemies[i]->isDead()) {
            if (sprite->checkCollision(_enemies[i])) {

                // Collision has occurred - kill the enemy
                _enemies[i]->explode();

                // Play a sound
                SoundPlayer::play(SoundPlayer::SOUND_CLANK_1);
                return true;
            }
        }
    }

    // No collision
    return false;
}
