#ifndef _CANNON_ENGINE_H_
#define _CANNON_ENGINE_H_

#include <SDL/SDL.h>
#include "spritebase.h"

/**
 * Basic cannon engine class, intended to be subclassed.
 */
class CannonEngine {
public:
	/**
	 * Constructor
	 */
	CannonEngine();

	/**
	 * Destructor
	 */
	virtual ~CannonEngine();

	/**
	 * Attempt to shoot a new bullet.
	 * @return True if a new bullet was fired.
	 */
	virtual bool shoot() = 0;

	/**
	 * Set this object's sprite.
	 * @param sprite Pointer to the sprite object.
	 * @return True if the sprite pointer was changed
	 */
	bool setSprite(SpriteBase* sprite);

protected:
	SpriteBase* _sprite;
};

#endif
