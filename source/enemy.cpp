#include "enemy.h"

// Include all powerups
#include "extralifepowerup.h"
#include "shieldpowerup.h"

Enemy::Enemy() {
	_killScore = 0;
	_shieldStrength = 1;
	_skipDrawFrames = 0;
	_dropPowerup = false;
}

Enemy::~Enemy() {
}

void Enemy::explode() {
	// Increase score
	Score::add(_killScore);

	// Create an explosion
	Sint32 explodeX = (_x >> 8) + (getWidth() / 2);
	Sint32 explodeY = (_y >> 8) + (getHeight() / 2);

	Game::getParticleManager()->createExplosion(explodeX, explodeY);

	// Play explosion sound
	SoundPlayer::play(SoundPlayer::SOUND_EXPLOSION_1);

	// Create score bubble
    switch (_killScore) {
	    case 100:
            Game::getSpriteManager()->add(new ScoreBubble(_x, _y, ScoreBubble::SCORE_BUBBLE_100));
            break;
	    case 500:
            Game::getSpriteManager()->add(new ScoreBubble(_x, _y, ScoreBubble::SCORE_BUBBLE_500));
            break;
	    case 1000:
            Game::getSpriteManager()->add(new ScoreBubble(_x, _y, ScoreBubble::SCORE_BUBBLE_1000));
            break;
	}

	// Add a powerup
	createPowerup();

    // Make enemy dead
	_isDead = true;
}

bool Enemy::run() {
	// Move the sprite
	if (_movementEngine != NULL) {
		_movementEngine->move();
	}

	// Shooting logic
	if (_cannonEngine != NULL) {
		_cannonEngine->shoot();
	}

	// Drawing
	if ((_renderEngine != NULL) && (_skipDrawFrames == 0)) {
	    _renderEngine->draw();
	} else if (_skipDrawFrames > 0) {
	    _skipDrawFrames--;
	}

	// Handle collisions with player bullets
	Sint32 damage = Game::getPlayerBulletManager()->checkCollision(this);

	if (damage > -1) {

        // Decrease shield power
        _shieldStrength -= damage;

        // Skip drawing frame to make enemy flash
        _skipDrawFrames = 2;

        // Shield exhausted?
        if (_shieldStrength == 0) {
            explode();
        }
    }

	return true;
}

void Enemy::setKillScore(Uint32 score) {
    _killScore = score;
}

void Enemy::setShieldStrength(Uint32 shots) {
    _shieldStrength = shots;
}

void Enemy::setDropPowerup(bool dropPowerup) {
    _dropPowerup = dropPowerup;
}

void Enemy::createPowerup() {

    if (_dropPowerup) {
        // Choose a random powerup type
        Uint8 type = rand() % 2;

        // Add the powerup
        switch (type) {
            case 0:
                // Shield
                ShieldPowerup* shield;
                shield = new ShieldPowerup();
                shield->setX(getX());
                shield->setY(getY());

                Game::getSpriteManager()->add(shield);
                break;
            case 1:
                // Extra life
                ExtraLifePowerup* life;
                life = new ExtraLifePowerup();
                life->setX(getX());
                life->setY(getY());

                Game::getSpriteManager()->add(life);
                break;
        }
    }
}
