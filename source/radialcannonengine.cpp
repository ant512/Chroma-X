#include "radialcannonengine.h"
#include "enemybulletbasic.h"
#include "soundplayer.h"

RadialCannonEngine::RadialCannonEngine() {
	_sprite = NULL;
	_shotTime = 30;//8;
	_shotTimer = 0;
	_angle = 0;
	_angleDelta = 20;
}

RadialCannonEngine::~RadialCannonEngine() {
}

bool RadialCannonEngine::shoot() {

    // Handle timer
    if (_shotTimer > 0) _shotTimer--;

    // Need to fire?
    if (_shotTimer == 0) {

        // Create new bullet
        EnemyBulletBasic* bullet = new EnemyBulletBasic();

        // Set bullet properties
        bullet->setX(_sprite->getX() + (_sprite->getWidth() / 2) - (bullet->getWidth() / 2));
        bullet->setY(_sprite->getY() + (_sprite->getHeight() / 2) - (bullet->getWidth() / 2));

        ((BasicMovementEngine*)bullet->getMovementEngine())->setXSpeed(MathTools::cos(_angle) * 2);
        ((BasicMovementEngine*)bullet->getMovementEngine())->setYSpeed(MathTools::sin(_angle) * 2);

        // Add bullet to manager
        Game::getEnemyBulletManager()->add(bullet);

        // Reset timer
        _shotTimer = _shotTime;

        // Increase firing angle
        _angle += _angleDelta;
        _angle &= 511;

        // Play sound
        SoundPlayer::play(SoundPlayer::SOUND_LASER_2);
    }

	return true;
}
