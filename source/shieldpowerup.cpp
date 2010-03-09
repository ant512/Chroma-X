#include "shieldpowerup.h"
#include "chopper.h"

ShieldPowerup::ShieldPowerup() {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());
    ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_POWERUP_SHIELD);

    // Set up movement
    setMovementEngine(new BasicMovementEngine(0, POWERUP_SPEED, 0, 0));
}

ShieldPowerup::~ShieldPowerup() {
}

bool ShieldPowerup::run() {
    GameSprite::run();

    // Activate the player's shield if there's a collision
    if (checkCollision(Game::getPlayer())) {
        Game::getPlayer()->activateShield();

        kill();
    }

    return true;
}
