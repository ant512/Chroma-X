#ifndef _UFO_H_
#define _UFO_H_

#include "enemy.h"
#include "animationrenderengine.h"
#include "radialcannonengine.h"

/**
 * Enemy UFO class.
 */
class UFO : public Enemy {
public:

    /**
     * Constructor.
     */
    UFO();

    /**
     * Destructor
     */
    ~UFO();
};

#endif
