#ifndef _EXTRA_LIFE_POWERUP_H_
#define _EXTRA_LIFE_POWERUP_H_

#include "gamesprite.h"
#include "bitmaprenderengine.h"
#include "basicmovementengine.h"

/**
 * Extra life powerup class.
 */
class ExtraLifePowerup : public GameSprite {
public:

    /**
     * Constructor.
     */
    ExtraLifePowerup();

    /**
     * Destructor
     */
    ~ExtraLifePowerup();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	bool run();
};

#endif
