#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

#include <SDL/SDL.h>
#include "gamesprite.h"
#include "bitmaprenderengine.h"

class TitleScreen {
public:

    /**
     * Run the title screen.
     */
    static void run();

private:

    /**
     * Draw the title screen.
     */
    static void draw();

    /**
     * Wait for the player to hit start
     */
    static void wait();
};

#endif
