#ifndef _BULLET_MANAGER_H_
#define _BULLET_MANAGER_H_

#include <SDL/SDL.h>
#include <vector>
#include "constants.h"
#include "soundplayer.h"

// Avoid cyclic dependencies
class BulletBase;
class GameSprite;

/**
 * Class to manage bullets
 */
class BulletManager {
public:
	/**
	 * Constructor.
	 */
    BulletManager();

	/**
	 * Destructor.
	 */
    ~BulletManager();

	/**
	 * Add a new bullet to the bullet list.
	 * @param bullet Pointer to the new bullet
	 */
    void add(BulletBase* bullet);

	/**
	 * Run the bullet manager.  Should be called every frame.
	 */
    void run();

    /**
     * Check for collisions between all bullets and another sprite
     * @return The value of the damage inflicted by a collision.
     * -1 indicates no collision.
     */
    Sint32 checkCollision(GameSprite* sprite);

private:
    std::vector<BulletBase*> _bullets;
};

#endif
