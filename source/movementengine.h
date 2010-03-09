#ifndef _MOVEMENT_ENGINE_H_
#define _MOVEMENT_ENGINE_H_

#include "spritebase.h"

/**
 * Basic sprite movement engine class, intended to be subclassed.
 */
class MovementEngine {
public:
	/**
	 * Constructor
	 */
	MovementEngine();

	/**
	 * Destructor
	 */
	virtual ~MovementEngine();

	/**
	 * Move this object's sprite.
	 * @return True if the sprite was moved successfully.
	 */
	virtual bool move() = 0;

	/**
	 * Set this object's sprite.
	 * @param sprite Pointer to the sprite object.
	 * @return True if the sprite pointer was changed
	 */
	bool setSprite(SpriteBase* sprite);

	/**
	 * Get the x speed of the engine.
	 * @return The x speed of the engine.
	 */
    virtual Sint32 getXSpeed();

	/**
	 * Get the y speed of the engine.
	 * @return The y speed of the engine.
	 */
    virtual Sint32 getYSpeed();

	/**
	 * Get the x acceleration of the engine.
	 * @return The x acceleration of the engine.
	 */
    virtual Sint32 getXAcceleration();

	/**
	 * Get the y acceleration of the engine.
	 * @return The y acceleration of the engine.
	 */
    virtual Sint32 getYAcceleration();

    /**
     * Set the x speed.
     * @param xSpeed The x speed.
     */
    virtual void setXSpeed(Sint32 xSpeed);

    /**
     * Set the y speed.
     * @param ySpeed The y speed.
     */
    virtual void setYSpeed(Sint32 ySpeed);

    /**
     * Set the x acceleration.
     * @param xSpeed The x acceleration.
     */
    virtual void setXAcceleration(Sint32 xAcceleration);

    /**
     * Set the y acceleration.
     * @param ySpeed The y acceleration.
     */
    virtual void setYAcceleration(Sint32 yAcceleration);

protected:
	SpriteBase* _sprite;
    Sint32 _xSpeed;
    Sint32 _ySpeed;
    Sint32 _xAcceleration;
    Sint32 _yAcceleration;
};

#endif
