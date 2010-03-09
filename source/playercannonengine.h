#ifndef _PLAYER_CANNON_ENGINE_H_
#define _PLAYER_CANNON_ENGINE_H_

#include <SDL/SDL.h>
#include "cannonengine.h"
#include "basicmovementengine.h"

/**
 * Player's cannon engine class.  Watches firebuttons and triggers bullets
 * as necessary.
 */
class PlayerCannonEngine : public CannonEngine {
public:
	/**
	 * Constructor
	 */
	PlayerCannonEngine();

	/**
	 * Destructor
	 */
	virtual ~PlayerCannonEngine();

	/**
	 * Attempt to shoot a new bullet.
	 * @return True if a new bullet was fired.
	 */
	virtual bool shoot();

private:
    Uint32 _shotTimer;
    Uint32 _shotTime;
};

#endif
