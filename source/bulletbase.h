#ifndef _BULLET_BASE_H_
#define _BULLET_BASE_H_

#include "gamesprite.h"
#include "bitmaprenderengine.h"
#include "basicmovementengine.h"

/**
 * Base bulleg class.
 */
class BulletBase : public GameSprite {
public:

    /**
     * Constructor.
     */
    BulletBase();

    /**
     * Destructor
     */
    ~BulletBase();

    /**
     * Return the amount of damage caused by this bullet.
     */
    Uint32 getDamage();

protected:
    Uint32 _damage;

};

#endif
