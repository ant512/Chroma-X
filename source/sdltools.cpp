#include "sdltools.h"

// Initialise static members
SDL_Surface* SDLTools::_screen = NULL;
SDL_Joystick* SDLTools::_joystick = NULL;

void SDLTools::init() {
    // Initialize SDL
    SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

    // Hide cursor
    SDL_ShowCursor(SDL_DISABLE);

    // Initialise joystick
    _joystick = SDL_JoystickOpen(0);

	// Initialise screen
    _screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16, SDL_SWSURFACE);
    SDL_ShowCursor(SDL_DISABLE);
}

SDL_Surface* SDLTools::getScreen() {
    return _screen;
}

SDL_Joystick* SDLTools::getJoystick() {
    return _joystick;
}

void SDLTools::shutdown() {

	// Delete the screen
	SDL_FreeSurface(_screen);

    SDL_Quit();

    // Do GP2X specific stuff
#ifdef PLATFORM_GP2X
    // Return to the menu
    chdir("/usr/gp2x");
	execl("/usr/gp2x/gp2xmenu", "/usr/gp2x/gp2xmenu", NULL);
#endif // PLATFORM_GP2X
}

void SDLTools::putPixel(Sint32 x, Sint32 y, Uint32 colour) {
    // Put pixel to screen
    putPixel(_screen, x, y, colour);
}

Uint32 SDLTools::getPixel(Sint32 x, Sint32 y) {
    // Get pixel from screen
    return getPixel(_screen, x, y);
}

bool SDLTools::isPixelTransparent(Sint32 x, Sint32 y) {
    // Get result from screen.
    return isPixelTransparent(_screen, x, y);
}

void SDLTools::putPixel(const SDL_Surface* surface, Sint32 x, Sint32 y, Uint32 colour) {
    if ((x >= 0) && (y >= 0) && (x < surface->w) && (y < surface->h)) {
        int bpp = surface->format->BytesPerPixel;
        /* Here p is the address to the pixel we want to set */
        Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

        switch (bpp) {
            case 1:
                *p = colour;
                break;

            case 2:
                *(Uint16 *)p = colour;
                break;

            case 3:
                if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                    p[0] = (colour >> 16) & 0xff;
                    p[1] = (colour >> 8) & 0xff;
                    p[2] = colour & 0xff;
                } else {
                    p[0] = colour & 0xff;
                    p[1] = (colour >> 8) & 0xff;
                    p[2] = (colour >> 16) & 0xff;
                }
                break;

            case 4:
                *(Uint32 *)p = colour;
                break;
        }
    }
}

Uint32 SDLTools::getPixel(const SDL_Surface* surface, Sint32 x, Sint32 y) {
    Uint32 colour = 0;

    if ((x >= 0) && (y >= 0) && (x < surface->w) && (y < surface->h)) {
        int bpp = surface->format->BytesPerPixel;
        /* Here p is the address to the pixel we want to set */
        Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

        switch(bpp)
        {
            case(1):
                colour = *p;
                break;

            case(2):
                colour = *(Uint16 *)p;
                break;

            case(3):
                if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                    colour = p[0] << 16 | p[1] << 8 | p[2];
                } else {
                    colour = p[0] | p[1] << 8 | p[2] << 16;
                }
                break;

            case(4):
                colour = *(Uint32 *)p;
                break;
        }
	}

	return colour;
}

bool SDLTools::isPixelTransparent(const SDL_Surface* surface, Sint32 x, Sint32 y) {
	return (getPixel(surface, x, y) == surface->format->colorkey);
}

void SDLTools::changeColour(SDL_Surface* surface, Uint32 originalColour, Uint32 newColour) {
    for (Sint32 x = 0; x < surface->w; x++) {
        for (Sint32 y = 0; y < surface->h; y++) {
            if (getPixel(surface, x, y) == originalColour) {
                putPixel(surface, x, y, newColour);
            }
        }
    }
}
