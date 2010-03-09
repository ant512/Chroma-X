#include "cloudmanager.h"
#include "cloud.h"

CloudManager::CloudManager() {
    for (Uint32 i = 0; i < CLOUDS; i++) {

        add(true);
    }
}

CloudManager::~CloudManager() {
    for (Uint32 i = 0; i < _sprites.size(); i++) {
        delete _sprites[i];
    }

    _sprites.clear();
}

void CloudManager::add(bool randomY) {

    Sint32 speed = 64 + (rand() % 64);

    Cloud* newCloud = new Cloud(speed);

    if (randomY) {
        newCloud->setY(rand() % PLAYFIELD_HEIGHT);
    }

    newCloud->setX(PLAYFIELD_X - newCloud->getWidth() + (rand() % (PLAYFIELD_WIDTH + newCloud->getWidth())));

    // Locate best place to insert cloud
    for (Uint32 i = _sprites.size(); i > 0; i--) {
        if (_sprites[i - 1]->getSpeed() < speed) {
            _sprites.insert(_sprites.begin() + i, newCloud);
            newCloud = NULL;
            break;
        }
    }

    // Did we insert it?
    if (newCloud != NULL) {
        // Insert at start
        _sprites.insert(_sprites.begin(), newCloud);
    }
}

void CloudManager::run() {
    for (Uint32 i = 0; i < _sprites.size(); i++) {
        _sprites[i]->run();

        // Has the enemy expired?
        if (_sprites[i]->isDead()) {

            // Delete dead enemy from list
            delete _sprites[i];
            _sprites.erase(_sprites.begin() + i);
            i--;
        }
    }

    // Add any missing clouds
    for (Uint32 i = CLOUDS - _sprites.size(); i > 0; i--) {
       add(false);
    }
}
