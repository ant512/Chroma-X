#ifndef _GAME_SPRITE_H_
#define _GAME_SPRITE_H_

#include <SDL/SDL.h>
#include "movementengine.h"
#include "cannonengine.h"
#include "renderengine.h"
#include "spritebase.h"

/**
 * Sprite class with slots for plugin movement, cannon and render engines.
 */
class GameSprite : public SpriteBase {
public:
	/**
	 * Constructor
	 */
	GameSprite();

	/**
	 * Destructor
	 */
	~GameSprite();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	virtual bool run();

	/**
	 * Give the sprite a new movement engine.
	 * @param movementEngine Pointer to the movement engine object.
	 * @return True if the property change occurred.
	 */
	bool setMovementEngine(MovementEngine* movementEngine);

	/**
	 * Give the sprite a new cannon engine.
	 * @param cannonEngine Pointer to the cannon engine object.
	 * @return True if the property change occurred.
	 */
	bool setCannonEngine(CannonEngine* cannonEngine);

	/**
	 * Give the sprite a new render engine.
	 * @param cannonEngine Pointer to the render engine object.
	 * @return True if the property change occurred.
	 */
	bool setRenderEngine(RenderEngine* renderEngine);

	/**
	 * Get the sprite's movement engine.
	 * @return The sprite's movement engine.
	 */
    MovementEngine* getMovementEngine();

	/**
	 * Get the sprite's cannon engine.
	 * @return The sprite's cannon engine.
	 */
    CannonEngine* getCannonEngine();

	/**
	 * Get the sprite's render engine.
	 * @return The sprite's render engine.
	 */
    RenderEngine* getRenderEngine();

	/**
	 * Check for collision with another sprite.
	 * @param sprite The other sprite.
	 * @return True if a collision occurred.
	 */
    bool checkCollision(GameSprite* y);

	/**
	 * Get the width of the sprite.
	 * @return The width of the sprite.
	 */
	const Uint32 getWidth() const;

	/**
	 * Get the height of the sprite.
	 * @return The height of the sprite.
	 */
	const Uint32 getHeight() const;

protected:
	MovementEngine* _movementEngine;
	CannonEngine* _cannonEngine;
	RenderEngine* _renderEngine;

	/**
	 * Check bounding box collisions with another sprite.
	 * @param sprite The other sprite.
	 * @return True if a collision occurred.
	 */
    bool checkBoundingCollision(GameSprite* y);

	/**
	 * Check pixel collisions with another sprite.
	 * @param sprite The other sprite.
	 * @return True if a collision occurred.
	 */
    bool checkPixelCollision(GameSprite* y);
};

#endif
