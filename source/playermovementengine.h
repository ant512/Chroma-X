#ifndef _PLAYER_MOVEMENT_ENGINE_H_
#define _PLAYER_MOVEMENT_ENGINE_H_

#include <SDL/SDL.h>
#include "constants.h"
#include "movementengine.h"
#include "gamesprite.h"

/**
 * Movement engine class designed for interaction with the d-pad.
 */
class PlayerMovementEngine : public MovementEngine {
public:

    /**
     * Pad status struct
     */
    typedef struct Pad {
        bool left;
        bool right;
        bool up;
        bool down;
    } Pad;

    /**
     * Constructor.
     */
    PlayerMovementEngine();

    /**
     * Destructor.
     */
    virtual ~PlayerMovementEngine();

	/**
	 * Move this object's sprite.
	 * @return True if the sprite was moved successfully.
	 */
	virtual bool move();

    /**
     * Get the pad state.
     * @return The pad state.
     */
    const PlayerMovementEngine::Pad* getPad() const;

private:

    Pad _pad;
    Sint32 _maxSpeed;

    /**
     * Read the input device's state and update the internal pad data
     */
    void updatePad();
};

#endif
