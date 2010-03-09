#ifndef _PLANE_2_H_
#define _PLANE_2_H_

#include "enemy.h"
#include "bitmaprenderengine.h"
#include "basicmovementengine.h"

/**
 * Enemy plane class #2.
 */
class Plane2 : public Enemy {
public:

    /**
     * Constructor.
     */
    Plane2();

    /**
     * Destructor
     */
    ~Plane2();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	bool run();

private:
    Sint32 _speed;
};

#endif
