#ifndef _CLOUD_MOVEMENT_ENGINE_H_
#define _CLOUD_MOVEMENT_ENGINE_H_

#include <SDL/SDL.h>
#include "constants.h"
#include "basicmovementengine.h"
#include "gamesprite.h"

/**
 * Movement engine class that will move a sprite in one direction.
 * Used for clouds - just overrides the boundary check to allow clouds
 * a greater vertical boundary.
 */
class CloudMovementEngine : public BasicMovementEngine {
public:

    /**
     * Constructor.
     */
    CloudMovementEngine(Sint32 xSpeed, Sint32 ySpeed, Sint32 xAcceleration, Sint32 yAcceleration);

    /**
     * Destructor.
     */
    virtual ~CloudMovementEngine();

protected:

    /**
     * Check if the sprite is out of bounds and therefore dead.
     */
    virtual void checkBoundaries();
};

#endif
