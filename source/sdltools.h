#ifndef _SDL_TOOLS_H_
#define _SDL_TOOLS_H_

#ifdef PLATFORM_GP2X
#include <unistd.h>
#endif // PLATFORM_GP2X

#include <SDL/SDL.h>
#include "constants.h"

#define GP2X_BUTTON_UP              (0)
#define GP2X_BUTTON_DOWN            (4)
#define GP2X_BUTTON_LEFT            (2)
#define GP2X_BUTTON_RIGHT           (6)
#define GP2X_BUTTON_UPLEFT          (1)
#define GP2X_BUTTON_UPRIGHT         (7)
#define GP2X_BUTTON_DOWNLEFT        (3)
#define GP2X_BUTTON_DOWNRIGHT       (5)
#define GP2X_BUTTON_CLICK           (18)
#define GP2X_BUTTON_A               (12)
#define GP2X_BUTTON_B               (13)
#define GP2X_BUTTON_X               (15)
#define GP2X_BUTTON_Y               (14)
#define GP2X_BUTTON_L               (11)
#define GP2X_BUTTON_R               (10)
#define GP2X_BUTTON_START           (8)
#define GP2X_BUTTON_SELECT          (9)
#define GP2X_BUTTON_VOLUP           (16)
#define GP2X_BUTTON_VOLDOWN         (17)

/**
 * Wrapper around some SDL functionality; also includes static pointers to screen,
 * joystick, etc.
 */
class SDLTools {
public:

	/**
	 * Initialise all necessary SDL systems.
	 */
	static void init();

	/**
	 * Shutdown SDL.
	 */
	static void shutdown();

	/**
	 * Plot a pixel to the screen surface
     * at the specified co-ordinates.
	 * @param x The x co-ordinate of the pixel.
	 * @param y The y co-ordinate of the pixel.
	 * @param colour The colour to plot.
	 */
	static void putPixel(Sint32 x, Sint32 y, Uint32 colour);

	/**
	 * Get the colour of the screen pixel at the
	 * specified co-ordinates
	 * @param x The x co-ordinate of the pixel.
	 * @param y The y co-ordinate of the pixel.
	 * @return The 32-bit colour of the pixel.
	 */
    static Uint32 getPixel(Sint32 x, Sint32 y);

    /**
     * Determine if the screen pixel at the specified
     * co-ordinates is transparent or not.
	 * @param x The x co-ordinate of the pixel.
	 * @param y The y co-ordinate of the pixel.
	 * @return True if the pixel is transparent.
	 */
    static bool isPixelTransparent(Sint32 x, Sint32 y);

	/**
	 * Plot a pixel to the surface at the specified co-ordinates.
	 * @param x The x co-ordinate of the pixel.
	 * @param y The y co-ordinate of the pixel.
	 * @param colour The colour to plot.
	 */
	static void putPixel(const SDL_Surface* surface, Sint32 x, Sint32 y, Uint32 colour);

	/**
	 * Get the colour of the surface's pixel at the
	 * specified co-ordinates
	 * @param x The x co-ordinate of the pixel.
	 * @param y The y co-ordinate of the pixel.
	 * @return The 32-bit colour of the pixel.
	 */
    static Uint32 getPixel(const SDL_Surface* surface, Sint32 x, Sint32 y);

    /**
     * Determine if the surface pixel at the specified
     * co-ordinates is transparent or not.
	 * @param x The x co-ordinate of the pixel.
	 * @param y The y co-ordinate of the pixel.
	 * @return True if the pixel is transparent.
	 */
    static bool isPixelTransparent(const SDL_Surface* surface, Sint32 x, Sint32 y);

	/**
	 * Return a pointer to the game's main surface.
	 * @return Pointer to the surface.
	 */
    static SDL_Surface* getScreen();

    /**
     * Return a pointer to the joystick.
     * @return Pointer to the joystick.
     */
    static SDL_Joystick* getJoystick();

    /**
     * Change all pixels that are the original colour to the new colour.
     * @param surface The surface to recolour.
     * @param originalColour The colour to change from.
     * @param newColour The colour to change to.
     */
    static void changeColour(SDL_Surface* surface, Uint32 originalColour, Uint32 newColour);

private:
	static SDL_Joystick* _joystick;
	static SDL_Surface* _screen;
};

#endif
