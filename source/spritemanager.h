#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

#include <SDL/SDL.h>
#include <vector>
#include "constants.h"

// Avoid cyclic dependencies by defining game sprite class
class GameSprite;

/**
 * Class to manage sprites
 */
class SpriteManager {
public:
	/**
	 * Constructor.
	 */
    SpriteManager();

	/**
	 * Destructor.
	 */
    ~SpriteManager();

	/**
	 * Add a new sprite to the sprite list.
	 * @param sprite Pointer to the new sprite.
	 */
    void add(GameSprite* sprite);

	/**
	 * Run the sprite manager.  Should be called every frame.
	 */
    void run();

    /**
     * Delete all sprites.
     */
    void clear();

private:
    std::vector<GameSprite*> _sprites;
};

#endif
