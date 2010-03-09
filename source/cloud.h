#ifndef _CLOUD_H_
#define _CLOUD_H_

#include "gamesprite.h"
#include "bitmaprenderengine.h"
#include "cloudmovementengine.h"

/**
 * Background cloud class.
 */
class Cloud : public GameSprite {
public:

    /**
     * Constructor.
     */
    Cloud(Sint32 speed);

    /**
     * Destructor
     */
    ~Cloud();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	bool run();

	/**
	 * Get the vertical speed of the cloud.
	 * @return The vertical speed of the cloud.
	 */
    Sint32 getSpeed();

private:
    Sint32 _speed;
};

#endif
