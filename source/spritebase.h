#ifndef _SPRITE_BASE_H_
#define _SPRITE_BASE_H_

#include <SDl/SDL.h>
#include "constants.h"
#include "sdltools.h"

/**
 * Basic sprite class, intended to be subclassed.
 */
class SpriteBase {
public:

	/**
	 * Constructor.
	 */
    SpriteBase();

	/**
	 * Destructor.
	 */
    virtual ~SpriteBase();

	/**
	 * Run the sprite code.  Should be called every frame.
	 */
	virtual bool run();

	/**
	 * Get the x co-ordinate of the sprite.
	 * @return The x co-ordinate of the sprite.
	 */
	const Sint32 getX() const;

	/**
	 * Get the y co-ordinate of the sprite.
	 * @return The y co-ordinate of the sprite.
	 */
	const Sint32 getY() const;

	/**
	 * Get the bitshifted x co-ordinate of the sprite
	 * with the lower byte representing a fixed-point fraction.
	 * @return The x co-ordinate of the sprite.
	 */
	const Sint32 getShiftedX() const;

	/**
	 * Get the y co-ordinate of the sprite.
	 * with the lower byte representing a fixed-point fraction.
	 * @return The y co-ordinate of the sprite.
	 */
	const Sint32 getShiftedY() const;

	/**
	 * Get the width of the sprite.
	 * @return The width of the sprite.
	 */
	virtual const Uint32 getWidth() const;

	/**
	 * Get the height of the sprite.
	 * @return The height of the sprite.
	 */
	virtual const Uint32 getHeight() const;

	/**
	 * Get the current status of the sprite - alive or dead.  Dead sprites are
	 * automatically removed from sprite managers.  Dead sprites should not be interacted
	 * with.
	 * @return True if the sprite is dead.	 * with the lower byte representing a fixed-point fraction.
	 */
	const bool isDead() const;

	/**
	 * Make the sprite dead.
	 */
	void kill();

	/**
	 * Set the x co-ordinate of the sprite.
	 * @param x The new x co-ordinate of the sprite.
	 */
	void setX(Sint32 x);

	/**
	 * Set the y co-ordinate of the sprite.
	 * @param y The new y co-ordinate of the sprite.
	 */
	void setY(Sint32 y);

	/**
	 * Set the x co-ordinate of the sprite using pre-bitshifted values
	 * with the lower byte representing a fixed-point fraction.
	 * @param x The new x co-ordinate of the sprite.
	 */
	void setShiftedX(Sint32 x);

	/**
	 * Set the y co-ordinate of the sprite using pre-bitshifted values
	 * with the lower byte representing a fixed-point fraction.
	 * @param y The new y co-ordinate of the sprite.
	 */
	void setShiftedY(Sint32 y);

protected:
	Sint32 _x;
	Sint32 _y;
	Uint32 _width;
	Uint32 _height;
	bool _isDead;
};

#endif
