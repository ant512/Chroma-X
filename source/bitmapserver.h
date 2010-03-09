#ifndef _BITMAP_SERVER_H_
#define _BITMAP_SERVER_H_

#include <SDL/SDL.h>
#include "sdltools.h"

const Uint32 BITMAP_TYPE_COUNT = 63;

/**
 * Class providing easy access to pre-loaded bitmap images.
 */
class BitmapServer {
public:

    /**
     * Bitmap types enum
     */
    enum BitmapType {
        BITMAP_CHOPPER_CENTRE = 0,
        BITMAP_CHOPPER_TILT_LEFT = 1,
        BITMAP_CHOPPER_TILT_RIGHT = 2,
        BITMAP_CHOPPER_TILT_FORWARDS = 3,
        BITMAP_CHOPPER_TILT_BACKWARDS = 4,
        BITMAP_GAME_BACKGROUND = 5,
        BITMAP_ROCKET_1 = 6,
        BITMAP_ROCKET_2 = 7,
        BITMAP_ROCKET_3 = 8,
        BITMAP_ROCKET_4 = 9,
        BITMAP_ROCKET_5 = 10,
        BITMAP_ROCKET_6 = 11,
        BITMAP_BLADES_1 = 12,
        BITMAP_BLADES_2 = 13,
        BITMAP_BLADES_3 = 14,
        BITMAP_BLADES_4 = 15,
        BITMAP_UFO_1 = 16,
        BITMAP_UFO_2 = 17,
        BITMAP_UFO_3 = 18,
        BITMAP_UFO_4 = 19,
        BITMAP_UFO_5 = 20,
        BITMAP_UFO_6 = 21,
        BITMAP_UFO_7 = 22,
        BITMAP_UFO_8 = 23,
        BITMAP_BULLET_CHOPPER_BASIC = 24,
        BITMAP_BULLET_ENEMY_BASIC = 25,
        BITMAP_PLANE1_CENTRE = 26,
        BITMAP_PLANE1_TILT_LEFT = 27,
        BITMAP_PLANE1_TILT_RIGHT = 28,
        BITMAP_PLANE2_CENTRE = 29,
        BITMAP_PLANE2_TILT_LEFT = 30,
        BITMAP_PLANE2_TILT_RIGHT = 31,
        BITMAP_CLOUD1 = 32,
        BITMAP_CLOUD2 = 33,
        BITMAP_CLOUD3 = 34,
        BITMAP_CLOUD4 = 35,
        BITMAP_CLOUD5 = 36,
        BITMAP_CLOUD6 = 37,
        BITMAP_SHIELD_1 = 38,
        BITMAP_SHIELD_2 = 39,
        BITMAP_SHIELD_3 = 40,
        BITMAP_SHIELD_4 = 41,
        BITMAP_SCORE_BUBBLE_100 = 42,
        BITMAP_SCORE_BUBBLE_500 = 43,
        BITMAP_SCORE_BUBBLE_1000 = 44,
        BITMAP_MISSION_TEXT1 = 45,
        BITMAP_MISSION_TEXT2 = 46,
        BITMAP_MISSION_TEXT3 = 47,
        BITMAP_MISSION_TEXT4 = 48,
        BITMAP_DIGIT0 = 49,
        BITMAP_DIGIT1 = 50,
        BITMAP_DIGIT2 = 51,
        BITMAP_DIGIT3 = 52,
        BITMAP_DIGIT4 = 53,
        BITMAP_DIGIT5 = 54,
        BITMAP_DIGIT6 = 55,
        BITMAP_DIGIT7 = 56,
        BITMAP_DIGIT8 = 57,
        BITMAP_DIGIT9 = 58,
        BITMAP_GAME_OVER_TEXT = 59,
        BITMAP_TITLE = 60,
        BITMAP_POWERUP_EXTRA_LIFE = 61,
        BITMAP_POWERUP_SHIELD = 62
    };

    /**
     * Get a pointer to the SDL surface represented by the supplied type.
     * @param type The type of bitmap requested.
     */
    static SDL_Surface* getBitmap(BitmapType type);

    /**
     * Initialise the bitmap server.  Loads all bitmaps.
     */
    static void init();

    /**
     * Shut down the bitmap server.  Frees all bitmaps.
     */
    static void shutdown();

    /**
     * Change fourth colour from current to new in all bitmaps.
     * @param newColour The colour to change to.
     */
    static void changeColour(Uint32 newColour);

    /**
     * Get the current colour.
     * @return The current colour.
     */
    static Uint32 getColour();

private:
    static SDL_Surface* _surfaces[BITMAP_TYPE_COUNT];
    static Uint32 _colour;

    /**
     * Load a bitmap from disk to RAM.
     * @param type The type of bitmap being loaded
	 * @param fileName The name of the bitmap file.
	 * @param transparent True to enable transparency.
	 */
	static void loadBitmap(BitmapType type, const char* fileName, bool transparent);
};

#endif
