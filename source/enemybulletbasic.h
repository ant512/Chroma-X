#ifndef _ENEMY_BULLET_BASIC_H_
#define _ENEMY_BULLET_BASIC_H_

#include "bulletbase.h"
#include "bitmaprenderengine.h"
#include "basicmovementengine.h"

/**
 * Basic bullets fired by the enemies.
 */
class EnemyBulletBasic : public BulletBase {
public:

    /**
     * Constructor.
     */
    EnemyBulletBasic();

    /**
     * Destructor
     */
    ~EnemyBulletBasic();
};

#endif
