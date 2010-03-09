#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

#include <SDL/SDL.h>
#include <vector>
#include "constants.h"

// Avoid cyclic dependencies by defining enemy class
class Enemy;
class GameSprite;

/**
 * Class to manage enemies
 */
class EnemyManager {
public:
	/**
	 * Constructor.
	 */
    EnemyManager();

	/**
	 * Destructor.
	 */
    ~EnemyManager();

	/**
	 * Add a new enemy to the enemy list.
	 * @param enemy Pointer to the new enemy.
	 */
    void add(Enemy* enemy);

	/**
	 * Run the enemy manager.  Should be called every frame.
	 */
    void run();

    /**
     * Check for a collision with any enemy
     */
    bool checkCollision(GameSprite* sprite);

private:
    std::vector<Enemy*> _enemies;
};

#endif
