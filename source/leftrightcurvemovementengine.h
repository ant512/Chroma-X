#ifndef _LEFT_RIGHT_CURVE_MOVEMENT_ENGINE_H_
#define _LEFT_RIGHT_CURVE_MOVEMENT_ENGINE_H_

#include <SDL/SDL.h>
#include "constants.h"
#include "movementengine.h"
#include "gamesprite.h"

/**
 * Movement engine class that will move a sprite from the left of the
 * playfield to the right in a curve.
 */
class LeftRightCurveMovementEngine : public MovementEngine {
public:

    /**
     * Constructor.
     */
    LeftRightCurveMovementEngine();

    /**
     * Destructor.
     */
    virtual ~LeftRightCurveMovementEngine();

	/**
	 * Move this object's sprite.
	 * @return True if the sprite was moved successfully.
	 */
	virtual bool move();

private:
    Sint32 _maxXAcceleration;
};

#endif
