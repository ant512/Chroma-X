#ifndef _SHIELD_POWERUP_H_
#define _SHIELD_POWERUP_H_

#include "gamesprite.h"
#include "bitmaprenderengine.h"
#include "basicmovementengine.h"

/**
 * Shield powerup class.
 */
class ShieldPowerup : public GameSprite {
public:

    /**
     * Constructor.
     */
    ShieldPowerup();

    /**
     * Destructor
     */
    ~ShieldPowerup();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	bool run();
};

#endif
