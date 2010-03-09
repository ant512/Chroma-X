#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#define COLOUR_BLACK SDL_MapRGB(SDLTools::getScreen()->format, 0, 0, 0)
#define COLOUR_WHITE SDL_MapRGB(SDLTools::getScreen()->format, 255, 255, 255)
#define COLOUR_TRANSPARENT SDL_MapRGB(SDLTools::getScreen()->format, 255, 0, 255)
#define COLOUR_RED SDL_MapRGB(SDLTools::getScreen()->format, 255, 0, 0)
#define COLOUR_GREY SDL_MapRGB(SDLTools::getScreen()->format, 172, 172, 172)
#define COLOUR_YELLOW SDL_MapRGB(SDLTools::getScreen()->format, 250, 252, 96)
#define COLOUR_GREEN SDL_MapRGB(SDLTools::getScreen()->format, 51, 165, 51)
#define COLOUR_BLUE SDL_MapRGB(SDLTools::getScreen()->format, 33, 134, 255)


// Screen description
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 240;
const int PLAYFIELD_X = 64;
const int PLAYFIELD_Y = 0;
const int PLAYFIELD_WIDTH = 192;
const int PLAYFIELD_HEIGHT = 240;

// Particles
const Uint32 MAX_PARTICLES = 200;
const Uint32 EXPLOSION_PARTICLES = 150;
const Uint32 SMOKE_TRAIL_PARTICLES = 2;

// Clouds
const Uint32 CLOUDS = 8;

// Score
const Sint32 SCORE_X = 309;
const Sint32 SCORE_Y = 20;
const Sint32 HISCORE_X = 309;
const Sint32 HISCORE_Y = 70;

// Powerups
const Sint32 POWERUP_SPEED = 224;

// Sounds
const Uint32 CHOPPER_GUN_CHANNEL = 1;

#endif
