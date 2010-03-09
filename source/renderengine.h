#ifndef _RENDER_ENGINE_H_
#define _RENDER_ENGINE_H_

#include "spritebase.h"

/**
 * Basic render engine class, intended to be subclassed.
 */
class RenderEngine {
public:
	/**
	 * Constructor
	 */
	RenderEngine();

	/**
	 * Destructor
	 */
	virtual ~RenderEngine();

	/**
	 * Draw this object.
	 * @return True if the sprite was drawn successfully.
	 */
	virtual bool draw() = 0;

	/**
	 * Set this object's sprite.
	 * @param sprite Pointer to the sprite object.
	 * @return True if the sprite pointer was changed
	 */
	bool setSprite(SpriteBase* sprite);

	/**
	 * Get the current surface.
	 * @return The current surface.
	 */
    virtual SDL_Surface* getSurface() = 0;

	/**
	 * Get the width of the current surface.
	 * @return The width of the current surface.
	 */
    virtual const Uint32 getWidth() const = 0;

	/**
	 * Get the height of the current surface.
	 * @return The height of the current surface.
	 */
    virtual const Uint32 getHeight() const = 0;

    /**
     * Enable/disable clipping.
     * @param clipping True to enable clipping.
     */
    void setClipping(const bool clipping);

protected:
	SpriteBase* _sprite;
	bool _clipped;
};

#endif
