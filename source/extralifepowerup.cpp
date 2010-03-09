#include "extralifepowerup.h"
#include "chopper.h"

ExtraLifePowerup::ExtraLifePowerup() {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());
    ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_POWERUP_EXTRA_LIFE);

    // Set up movement
    setMovementEngine(new BasicMovementEngine(0, POWERUP_SPEED, 0, 0));
}

ExtraLifePowerup::~ExtraLifePowerup() {
}

bool ExtraLifePowerup::run() {
    GameSprite::run();

    // Add an extra life to the player if there's a collision
    if (checkCollision(Game::getPlayer())) {
        Game::getPlayer()->addLife();

        kill();
    }

    return true;
}
