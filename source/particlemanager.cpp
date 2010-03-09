#include "particlemanager.h"
#include "particle.h"

ParticleManager::ParticleManager() {
}

ParticleManager::~ParticleManager() {
    for (Uint32 i = 0; i < _particles.size(); i++) {
        delete _particles[i];
    }

    _particles.clear();
}

void ParticleManager::add(Uint32 colour, Sint32 x, Sint32 y, Sint32 speedX,
         Sint32 speedY, Sint32 accelerationX, Sint32 accelerationY,
         Sint32 speedLimitX, Sint32 speedLimitY, Uint32 lifeTime) {

    // Attempt to add a new particle
    if (_particles.size() < MAX_PARTICLES) {

        // Space remaining in vector, so add new
        _particles.push_back(new Particle(colour, x, y, speedX, speedY,
                             accelerationX, accelerationY, speedLimitX,
                             speedLimitY, lifeTime));
    } else {

        // No space in vector, so remove particle from front of
        // vector, change properties, and add to end
        Particle* particle = _particles[0];
        particle->setColour(colour);
        particle->setX(x);
        particle->setY(y);
        particle->setSpeedX(speedX);
        particle->setSpeedY(speedY);
        particle->setAccelerationX(accelerationX);
        particle->setAccelerationY(accelerationY);
        particle->setSpeedLimitX(speedLimitX);
        particle->setSpeedLimitY(speedLimitY);
        particle->setLifeTime(lifeTime);
        particle->setTimer(0);

        _particles.erase(_particles.begin());
        _particles.push_back(particle);
    }
}

void ParticleManager::run() {
    for (Uint32 i = 0; i < _particles.size(); i++) {
        _particles[i]->run();

        // Has the particle expired?
        if (_particles[i]->isDead()) {

            // Delete dead particle from list
            delete _particles[i];
            _particles.erase(_particles.begin() + i);
            i--;
        }
    }
}

// Note - velocity isn't divided into x and y components, so
// speed isn't really accurately modelled.
void ParticleManager::createExplosion(Sint32 x, Sint32 y) {

    Uint32 colour = COLOUR_BLACK;
    Sint32 speedX;
    Sint32 speedY;
    Sint32 accelerationX;
    Sint32 accelerationY;
    Sint32 speedLimitX;
    Sint32 speedLimitY;
    Uint32 lifeTime;

    for (Uint8 i = 0; i < EXPLOSION_PARTICLES; i++) {

        speedX = ((rand() % 30) - (rand() % 30)) << 5;
        speedY = ((rand() % 30) - (rand() % 30)) << 5;
        accelerationX = (rand() % 25);
        accelerationY = (rand() % 25);


        if (speedX > 0) accelerationX = -accelerationX;
        if (speedY > 0) accelerationY = -accelerationY;

        speedLimitX = 0;
        speedLimitY = 0;

        lifeTime = 100 + (rand() % 100);

        add(colour, x, y, speedX, speedY, accelerationX, accelerationY, speedLimitX, speedLimitY, lifeTime);
    }
}

void ParticleManager::createSmokeTrail(Sint32 x, Sint32 y, Sint32 objectSpeedX, Sint32 objectSpeedY) {

    Uint32 colour = COLOUR_GREY;
    Sint32 speedX;
    Sint32 speedY;
    Sint32 accelerationX;
    Sint32 accelerationY;
    Sint32 speedLimitX;
    Sint32 speedLimitY;
    Uint32 lifeTime;

    for (Uint8 i = 0; i < SMOKE_TRAIL_PARTICLES; i++) {

        speedX = -objectSpeedX + (((rand() % 20) - (rand() % 20)) << 5);
        speedY = -objectSpeedY + (((rand() % 10) - (rand() % 20)) << 5);

        accelerationX = (rand() % 25);
        accelerationY = (rand() % 25);

        if (speedX > 0) accelerationX = -accelerationX;
        if (speedY > 0) accelerationY = -accelerationY;

        speedLimitX = 0;
        speedLimitY = 0;

        lifeTime = 10 + (rand() % 20);

        add(colour, x, y, speedX, speedY, accelerationX, accelerationY, speedLimitX, speedLimitY, lifeTime);
    }
}
