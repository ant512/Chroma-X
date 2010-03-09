#ifndef _CHOPPER_H_
#define _CHOPPER_H_

#include "gamesprite.h"
#include "bitmaprenderengine.h"
#include "playermovementengine.h"
#include "playercannonengine.h"
#include "blades.h"
#include "bitmapserver.h"
#include "shield.h"

/**
 * Player's helicopter sprite.
 */
class Chopper : public GameSprite {
public:

    /**
     * Constructor.
     */
    Chopper();

    /**
     * Destructor
     */
    ~Chopper();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	bool run();

	/**
	 * Activate the shield.
	 */
    void activateShield();

    /**
     * Explode the chopper.
     */
    void explode();

    /**
     * Add an extra life.
     */
    void addLife();

private:
    Blades* _blades;
    Shield* _shield;
    Uint32 _bladeOffsetX;
    Uint32 _bladeOffsetY;
    Uint32 _shieldTimer;
    Uint32 _shieldTime;
    Uint32 _lives;
    Uint32 _deadTime;
    Uint32 _deadTimer;
    Uint32 _maxLives;
};

#endif
