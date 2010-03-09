#include "cloud.h"

Cloud::Cloud(Sint32 speed) {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());

    Uint8 rnd = rand() % 3;
    BitmapServer::BitmapType type = BitmapServer::BITMAP_CLOUD2;
    switch (rnd) {
        case 0:
            type = BitmapServer::BITMAP_CLOUD2;
            break;
        case 1:
            type = BitmapServer::BITMAP_CLOUD4;
            break;
        case 2:
            type = BitmapServer::BITMAP_CLOUD5;
            break;
    }
    ((BitmapRenderEngine*)_renderEngine)->setBitmap(type);

    _speed = speed;

    // Set initial Y
    setY(-(((BitmapRenderEngine*)_renderEngine)->getSurface()->h << 1) + (rand() % -((BitmapRenderEngine*)_renderEngine)->getSurface()->h));

    // Set up movement
    setMovementEngine(new CloudMovementEngine(0, _speed, 0, 0));
}

Cloud::~Cloud() {
}

bool Cloud::run() {
    GameSprite::run();

    return true;
}

Sint32 Cloud::getSpeed() {
    return _speed;
}
