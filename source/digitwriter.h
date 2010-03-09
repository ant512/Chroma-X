#ifndef _DIGIT_WRITER_H_
#define _DIGIT_WRITER_H_

#include <SDL/SDL.h>
#include "bitmaprenderengine.h"

class GameSprite;

class DigitWriter {
public:

	/**
	 * Output a value to the screen
	 */
    static void draw(Sint32 x, Sint32 y, Uint32 value, Uint32 backgroundColour, bool erase);

private:
	static GameSprite* _sprite;
};

#endif
