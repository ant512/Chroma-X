#ifndef _CHOPPER_BULLET_BASIC_H_
#define _CHOPPER_BULLET_BASIC_H_

#include "bulletbase.h"
#include "bitmaprenderengine.h"
#include "basicmovementengine.h"

/**
 * Basic bullets fired by the player's chopper.
 */
class ChopperBulletBasic : public BulletBase {
public:

    /**
     * Constructor.
     */
    ChopperBulletBasic();

    /**
     * Destructor
     */
    ~ChopperBulletBasic();
};

#endif
