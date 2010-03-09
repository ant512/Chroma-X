#ifndef _ANIMATION_RENDER_ENGINE_H_
#define _ANIMATION_RENDER_ENGINE_H_

#include <SDl/SDL.h>
#include "constants.h"
#include "game.h"
#include "sdltools.h"
#include "spritebase.h"
#include "bitmapserver.h"
#include "renderengine.h"
#include "animation.h"

/**
 * Render engine that provides animation.
 */
class AnimationRenderEngine : public RenderEngine {
public:

	/**
	 * Constructor.
	 */
    AnimationRenderEngine();

	/**
	 * Destructor
	 */
    virtual ~AnimationRenderEngine();

	/**
	 * Draw the current bitmap.
	 */
	virtual bool draw();

	/**
	 * Get the width of the current surface.
	 * @return The width of the current surface.
	 */
    const Uint32 getWidth() const;

	/**
	 * Get the height of the current surface.
	 * @return The height of the current surface.
	 */
    const Uint32 getHeight() const;

    /**
     * Get the animation
     * @return Pointer to the animation object.
     */
    Animation* getAnimation();


	/**
	 * Get the current surface.
	 * @return The current surface.
	 */
    SDL_Surface* getSurface();

protected:
	Animation* _animation;
};

#endif
