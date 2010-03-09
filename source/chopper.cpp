#include "chopper.h"

Chopper::Chopper() {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());
    ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_CHOPPER_CENTRE);

    // Set up movement
    setMovementEngine(new PlayerMovementEngine());

    // Set up firing mechanism
    setCannonEngine(new PlayerCannonEngine());

    // Create blades
    _blades = new Blades();
    _bladeOffsetX = 2816;
    _bladeOffsetY = 2048;

    // Create shield
    _shield = new Shield();
    _shieldTime = 360;
    _shieldTimer = _shieldTime;

    // Set up life/death variables
    _maxLives = 3;
    _lives = _maxLives;
    _deadTime = 240;
    _deadTimer = 0;

    // Reset x and y positions
    setX(PLAYFIELD_X + (PLAYFIELD_WIDTH / 2) - (getWidth() / 2));
    setY(PLAYFIELD_HEIGHT);
}

Chopper::~Chopper() {
}

bool Chopper::run() {

    if ((_deadTimer == 0) && (_lives > 0)) {
        GameSprite::run();

        // Move blades to match chopper
        _blades->setShiftedX(_x - _bladeOffsetX);
        _blades->setShiftedY(_y - _bladeOffsetY);

        // Move shield to match chopper
        _shield->setShiftedX(_x - _bladeOffsetX);
        _shield->setShiftedY(_y - _bladeOffsetY);

        // Run blades
        _blades->run();

        // Run shield
        if (_shieldTimer > 0) {
            _shield->run();
            _shieldTimer--;
        }

        // Choose bitmap depending on pad state
        const PlayerMovementEngine::Pad* pad = ((PlayerMovementEngine*)_movementEngine)->getPad();

        if (pad->left) {
            ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_CHOPPER_TILT_LEFT);
        } else if (pad->right) {
            ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_CHOPPER_TILT_RIGHT);
        } else if (pad->up) {
            ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_CHOPPER_TILT_FORWARDS);
        } else if (pad->down) {
            ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_CHOPPER_TILT_BACKWARDS);
        } else {
            ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_CHOPPER_CENTRE);
        }

        // Handle collisions with enemy bullets
        if (_shieldTimer == 0) {
            Sint32 damage = Game::getEnemyBulletManager()->checkCollision(this);

            if (damage > -1) {
                explode();
            }

            // Handle collisions with enemies
            if (Game::getEnemyManager()->checkCollision(this)) {
                explode();
            }
        }
    } else {
        // Decrease dead time
        _deadTimer--;

        // No more dead time?
        if (_deadTimer == 0) {
            // Create shield
            _shieldTimer = _shieldTime;

            // Reset x and y positions
            setX(PLAYFIELD_X + (PLAYFIELD_WIDTH / 2) - (getWidth() / 2));
            setY(PLAYFIELD_HEIGHT);
        }
    }

    return true;
}

void Chopper::activateShield() {
    _shieldTimer = _shieldTime;
}

void Chopper::explode() {
    // Decrease life counter
    _lives--;

    // Set up dead timer
    _deadTimer = _deadTime;

    // Check for game over
    if (_lives == 0) {
        Game::gameOver();
    }

	// Create an explosion
	Sint32 explodeX = (_x >> 8) + (getWidth() / 2);
	Sint32 explodeY = (_y >> 8) + (getHeight() / 2);

	Game::getParticleManager()->createExplosion(explodeX, explodeY);

	// Play explosion sound
	SoundPlayer::play(SoundPlayer::SOUND_EXPLOSION_1);
}

void Chopper::addLife() {
    if (_lives < _maxLives) {
        _lives++;

        // Update the life indicator
    }
}
