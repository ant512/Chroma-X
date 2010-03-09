#ifndef _ROCKET_H_
#define _ROCKET_H_

#include "enemy.h"
#include "animationrenderengine.h"
#include "basicmovementengine.h"

/**
 * Enemy rocket class.
 */
class Rocket : public Enemy {
public:

    /**
     * Constructor.
     */
    Rocket();

    /**
     * Destructor
     */
    ~Rocket();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	bool run();

private:
    Sint32 _speed;
};

#endif
