#ifndef _RADIAL_CANNON_ENGINE_H_
#define _RADIAL_CANNON_ENGINE_H_

#include <SDL/SDL.h>
#include "cannonengine.h"
#include "basicmovementengine.h"
#include "mathtools.h"

/**
 * Radial cannon engine class.  Produces a stream of bullets
 * in a circle.
 */
class RadialCannonEngine : public CannonEngine {
public:
	/**
	 * Constructor
	 */
	RadialCannonEngine();

	/**
	 * Destructor
	 */
	virtual ~RadialCannonEngine();

	/**
	 * Attempt to shoot a new bullet.
	 * @return True if a new bullet was fired.
	 */
	virtual bool shoot();

private:
    Uint32 _shotTimer;
    Uint32 _shotTime;
    Sint32 _angle;
    Sint32 _angleDelta;
};

#endif
