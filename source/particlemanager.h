#ifndef _PARTICLE_MANAGER_H_
#define _PARTICLE_MANAGER_H_

#include <SDL/SDL.h>
#include <vector>
#include "constants.h"

// Avoid cyclic dependencies by defining particle class
class Particle;

/**
 * Class providing simple methods for creating particle-based graphical effects.
 * Basically functions as a wrapper around the vector class.
 */
class ParticleManager {
public:
	/**
	 * Constructor.
	 */
    ParticleManager();

	/**
	 * Destructor.
	 */
    ~ParticleManager();

	/**
	 * Add a new particle to the particle list.
	 * Will attempt to create a new particle if there is space in the list, or will
	 * remove the first (therefore oldest) particle in the list and append the new particle
	 * to the end.  This ensures that all particles get a chance to exist, and old
	 * particles do not tie up any slots.
	 * @param colour The colour of the particle.
	 * @param x The initial x co-ordinate of the particle.
	 * @param y The initial y co-ordinate of the particle.
	 * @param speedX The x component of the particle's velocity (lower byte is treated as
	 * a fractional part).
	 * @param speedY The y component of the particle's velocity (lower byte is treated as
	 * a fractional part).
	 * @param accelerationX The x component of the particle's acceleration (lower byte
	 * is treated as a fractional part).
	 * @param accelerationY The y component of the particle's acceleration (lower byte
	 * is treated as a fractional part).
	 * @param speedLimitX The x component of the speed at which the particle will be
	   considered to be dead (lower byte is treated as a fractional part).
	 * @param speedLimitY The y component of the speed at which the particle will be
	   considered to be dead (lower byte is treated as a fractional part).
	 * @param lifeTime The number of frames that the particle will exist for.  Setting this
	   to 0 results in a particle that won't automatically expire after a set period.
	 */
    void add(Uint32 colour, Sint32 x, Sint32 y, Sint32 speedX,
             Sint32 speedY, Sint32 accelerationX, Sint32 accelerationY,
             Sint32 speedLimitX, Sint32 speedLimitY, Uint32 lifeTime = 0);

	/**
	 * Run the particle manager.  Should be called every frame.
	 */
    void run();

	/**
	 * Create an explosion starting at the specified co-ordinates.
	 * @param x The x co-ordinate of the explosion's centre.
	 * @param y The y co-ordinate of the explosion's centre.
	 */
    void createExplosion(Sint32 x, Sint32 y);

    /**
     * Create a piece of a smoke trail at the specified co-ordinates.
     * The smoke trail travels in the opposite direction to the object that
     * creates it, so object velocity needs to be passed into the function.
     * @param x The x co-ordinate of the smoke trail piece.
     * @param y The y co-ordinate of the smoke trail piece.
     * @param objectSpeedX The x component of the originating object's velocity.
     * @param objectSpeedY The y component of the originating object's velocity.
     */
    void createSmokeTrail(Sint32 x, Sint32 y, Sint32 objectSpeedX, Sint32 objectSpeedY);

private:
    std::vector<Particle*> _particles;
};

#endif
