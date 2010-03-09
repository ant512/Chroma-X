#ifndef _BASIC_MOVEMENT_ENGINE_H_
#define _BASIC_MOVEMENT_ENGINE_H_

#include <SDL/SDL.h>
#include "constants.h"
#include "movementengine.h"
#include "gamesprite.h"

/**
 * Movement engine class that will move a sprite in one direction.
 */
class BasicMovementEngine : public MovementEngine {
public:

    /**
     * Constructor.
     */
    BasicMovementEngine(Sint32 xSpeed, Sint32 ySpeed, Sint32 xAcceleration, Sint32 yAcceleration);

    /**
     * Destructor.
     */
    virtual ~BasicMovementEngine();

	/**
	 * Move this object's sprite.
	 * @return True if the sprite was moved successfully.
	 */
	virtual bool move();

	/**
	 * Set the y speed of the engine.
	 * @param ySpeed The y speed.
	 */
    virtual void setYSpeed(Sint32 ySpeed);

protected:

    /**
     * Check if the sprite is out of bounds and therefore dead.
     */
    virtual void checkBoundaries();
};

#endif
