#ifndef _BITMAP_RENDER_ENGINE_H_
#define _BITMAP_RENDER_ENGINE_H_

#include <SDl/SDL.h>
#include "constants.h"
#include "game.h"
#include "sdltools.h"
#include "spritebase.h"
#include "bitmapserver.h"
#include "renderengine.h"

/**
 * Render engine that provides bitmap rendering.
 */
class BitmapRenderEngine : public RenderEngine {
public:

	/**
	 * Constructor.
	 */
    BitmapRenderEngine();

	/**
	 * Destructor
	 */
    virtual ~BitmapRenderEngine();

	/**
	 * Set the current surface bitmap
	 * @param type The type of the bitmap.
	 */
	virtual void setBitmap(BitmapServer::BitmapType type);

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
	 * Get the current surface.
	 * @return The current surface.
	 */
    SDL_Surface* getSurface();

protected:
	SDL_Surface* _surface;
};

#endif
