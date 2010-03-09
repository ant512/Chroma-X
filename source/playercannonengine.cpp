#include "playercannonengine.h"
#include "chopperbulletbasic.h"

PlayerCannonEngine::PlayerCannonEngine() {
	_sprite = NULL;
	_shotTime = 8;
	_shotTimer = 0;
}

PlayerCannonEngine::~PlayerCannonEngine() {
}

bool PlayerCannonEngine::shoot() {

    // Handle timer
    if (_shotTimer > 0) _shotTimer--;

    // Handle input
    bool fireRequested = false;

    #ifdef PLATFORM_GP2X
    fireRequested = SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_B);
    #else
    Uint8* keyState = SDL_GetKeyState(NULL);
    fireRequested = keyState[SDLK_SPACE];
    #endif

    // Need to fire?
    if ((fireRequested) && (_shotTimer == 0)) {

        // Create new bullet
        ChopperBulletBasic* bullet = new ChopperBulletBasic();

        // Set bullet properties
        bullet->setX(_sprite->getX() + (_sprite->getWidth() / 2) - (bullet->getWidth() / 2));
        bullet->setY(_sprite->getY());

        // Add bullet to manager
        Game::getPlayerBulletManager()->add(bullet);

        // Reset timer
        _shotTimer = _shotTime;

        // Play shoot sound
        SoundPlayer::play(SoundPlayer::SOUND_MACHINE_GUN_1, CHOPPER_GUN_CHANNEL);
    }

	return true;
}
