#ifndef _MISSION_TEXT_MOVEMENT_ENGINE_H_
#define _MISSION_TEXT_MOVEMENT_ENGINE_H_

#include <SDL/SDL.h>
#include "constants.h"
#include "movementengine.h"
#include "gamesprite.h"

/**
 * Movement engine class that will move a sprite up the screen, decelerating
 * until it stops, pause a while, then accelerate off again.
 */
class MissionTextMovementEngine : public MovementEngine {
public:

    /**
     * Constructor.
     */
    MissionTextMovementEngine();

    /**
     * Destructor.
     */
    virtual ~MissionTextMovementEngine();

	/**
	 * Move this object's sprite.
	 * @return True if the sprite was moved successfully.
	 */
	virtual bool move();

private:

    Sint32 _ySpeed;
    Sint32 _yAcceleration;
};

#endif
