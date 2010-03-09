#ifndef _BITMAP_LIST_RENDER_ENGINE_H_
#define _BITMAP_LIST_RENDER_ENGINE_H_

#include <SDl/SDL.h>
#include <vector>
#include "constants.h"
#include "game.h"
#include "sdltools.h"
#include "spritebase.h"
#include "bitmapserver.h"
#include "renderengine.h"

/**
 * Render engine that provides a list of bitmaps, any of which can be
 * chosen as the current output bitmap.
 */
class BitmapListRenderEngine : public RenderEngine {
public:

	/**
	 * Constructor.
	 */
    BitmapListRenderEngine();

	/**
	 * Destructor
	 */
    virtual ~BitmapListRenderEngine();

	/**
	 * Add a new surface bitmap to the engine.
	 * @param type The type of the bitmap to add.
	 */
	virtual void addBitmap(BitmapServer::BitmapType type);

	/**
	 * Draw the current bitmap.
	 */
	virtual bool draw();

	/**
	 * Set the number of the surface to work with.
	 * @param surfaceIndex The number of the surface.
	 */
	void setCurrentSurfaceIndex(Uint32 surfaceIndex);

	/**
	 * Get the number of the surface currently in use.
	 * @return The surface index.
	 */
	const Uint32 getCurrentSurfaceIndex() const;

	/**
	 * Get the width of the current surface.
	 * @return The width of the current surface.
	 */
    const Uint32 getCurrentWidth() const;

	/**
	 * Get the height of the current surface.
	 * @return The height of the current surface.
	 */
    const Uint32 getCurrentHeight() const;

	/**
	 * Get the current surface.
	 * @return The current surface.
	 */
    SDL_Surface* getSurface();

protected:
	std::vector<SDL_Surface*> _surfaces;
	Uint32 _currentSurface;
};

#endif
