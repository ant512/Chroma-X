#ifndef _PLANE_1_H_
#define _PLANE_1_H_

#include "enemy.h"
#include "bitmaprenderengine.h"
#include "basicmovementengine.h"
#include "leftrightcurvemovementengine.h"

/**
 * Enemy plane class.
 */
class Plane1 : public Enemy {
public:

    /**
     * Constructor.
     */
    Plane1();

    /**
     * Destructor
     */
    ~Plane1();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	bool run();

private:
    Sint32 _speed;
};

#endif
