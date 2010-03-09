#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include <SDl/SDL.h>
#include "constants.h"
#include "game.h"
#include "sdltools.h"

class Particle {
public:
	/**
	 * Constructor.
	 */
    Particle(Uint32 colour, Sint32 x, Sint32 y, Sint32 speedX, Sint32 speedY, Sint32 accelerationX, Sint32
 accelerationY, Sint32 speedLimitX, Sint32 speedLimitY, Uint32 lifeTime = 0);

	/**
	 * Destructor.
	 */
    ~Particle();

	/**
	 * Run the particle logic.  Should be called once per frame.
	 */
	bool run();

	/**
	 * Get the x co-ordinate of the particle.
	 * @return The x co-ordinate of the particle.
	 */
	const Sint32 getX() const;

	/**
	 * Get the y co-ordinate of the particle.
	 * @return The y co-ordinate of the particle.
	 */
	const Sint32 getY() const;
	const Sint32 getSpeedX() const;
	const Sint32 getSpeedY() const;
	const Sint32 getAccelerationX() const;
	const Sint32 getAccelerationY() const;
	const Sint32 getSpeedLimitX() const;
	const Sint32 getSpeedLimitY() const;
	const Uint32 getLifeTime() const;
	const Uint32 getTimer() const;
	const bool isDead() const;
	const Uint32 getColour() const;

	void setX(Sint32 x);
	void setY(Sint32 y);
	void setSpeedX(Sint32 speedX);
	void setSpeedY(Sint32 speedY);
	void setAccelerationX(Sint32 accelerationX);
	void setAccelerationY(Sint32 accelerationY);
	void setSpeedLimitX(Sint32 speedLimitX);
	void setSpeedLimitY(Sint32 speedLimitY);
	void setLifeTime(Uint32 lifeTime);
	void setTimer(Uint32 timer);
	void setDead(bool isDead);
	void setColour(Uint32 colour);

	/**
	 * Draw the particle to the game's surface.
	 */
	const void draw() const;


private:
	Sint32 _x;
	Sint32 _y;
	Sint32 _speedX;
	Sint32 _speedY;
	Sint32 _accelerationX;
	Sint32 _accelerationY;
	Sint32 _speedLimitX;
	Sint32 _speedLimitY;
	Uint32 _lifeTime;
	Uint32 _timer;
	Sint32 _width;
	Sint32 _height;
	bool _isDead;
	Uint32 _colour;
};

#endif
