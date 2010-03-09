#include <SDl/SDL.h>

#include "constants.h"
#include "game.h"
#include "sdltools.h"
#include "bitmapserver.h"
#include "soundplayer.h"
#include "titlescreen.h"

int main(int argc, char* args[]) {
    // Initilise all SDL components
    SDLTools::init();

    // Initialise the bitmap server
    BitmapServer::init();

    // Initialise the sound player
    SoundPlayer::init();

    // Run the title screen
    TitleScreen::run();

    // Run the game main loop
    Game::run();

    // Shutdown the bitmap server
    BitmapServer::shutdown();

    // Shutdown the sound player
    SoundPlayer::shutdown();

    // Shutdown SDL
    SDLTools::shutdown();

    return 0;
}

