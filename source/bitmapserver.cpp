#include "bitmapserver.h"

SDL_Surface* BitmapServer::_surfaces[BITMAP_TYPE_COUNT];
Uint32 BitmapServer::_colour = 0;

SDL_Surface* BitmapServer::getBitmap(BitmapType type) {
    return _surfaces[type];
}

Uint32 BitmapServer::getColour() {
    return _colour;
}

void BitmapServer::init() {
    loadBitmap(BITMAP_CHOPPER_CENTRE, "./gfx/chopper/centre.bmp", true);
    loadBitmap(BITMAP_CHOPPER_TILT_LEFT, "./gfx/chopper/tiltleft.bmp", true);
    loadBitmap(BITMAP_CHOPPER_TILT_RIGHT, "./gfx/chopper/tiltright.bmp", true);
    loadBitmap(BITMAP_CHOPPER_TILT_FORWARDS, "./gfx/chopper/tiltforward.bmp", true);
    loadBitmap(BITMAP_CHOPPER_TILT_BACKWARDS, "./gfx/chopper/tiltback.bmp", true);
    loadBitmap(BITMAP_GAME_BACKGROUND, "./gfx/bg/bg.bmp", false);
    loadBitmap(BITMAP_ROCKET_1, "./gfx/rocket/rocket1.bmp", true);
    loadBitmap(BITMAP_ROCKET_2, "./gfx/rocket/rocket2.bmp", true);
    loadBitmap(BITMAP_ROCKET_3, "./gfx/rocket/rocket3.bmp", true);
    loadBitmap(BITMAP_ROCKET_4, "./gfx/rocket/rocket4.bmp", true);
    loadBitmap(BITMAP_ROCKET_5, "./gfx/rocket/rocket5.bmp", true);
    loadBitmap(BITMAP_ROCKET_6, "./gfx/rocket/rocket6.bmp", true);
    loadBitmap(BITMAP_BLADES_1, "./gfx/blades/blades1.bmp", true);
    loadBitmap(BITMAP_BLADES_2, "./gfx/blades/blades2.bmp", true);
    loadBitmap(BITMAP_BLADES_3, "./gfx/blades/blades3.bmp", true);
    loadBitmap(BITMAP_BLADES_4, "./gfx/blades/blades4.bmp", true);
    loadBitmap(BITMAP_UFO_1, "./gfx/ufo/ufo1.bmp", true);
    loadBitmap(BITMAP_UFO_2, "./gfx/ufo/ufo2.bmp", true);
    loadBitmap(BITMAP_UFO_3, "./gfx/ufo/ufo3.bmp", true);
    loadBitmap(BITMAP_UFO_4, "./gfx/ufo/ufo4.bmp", true);
    loadBitmap(BITMAP_UFO_5, "./gfx/ufo/ufo5.bmp", true);
    loadBitmap(BITMAP_UFO_6, "./gfx/ufo/ufo6.bmp", true);
    loadBitmap(BITMAP_UFO_7, "./gfx/ufo/ufo7.bmp", true);
    loadBitmap(BITMAP_UFO_8, "./gfx/ufo/ufo8.bmp", true);
    loadBitmap(BITMAP_BULLET_CHOPPER_BASIC, "./gfx/bullets/chopperbasicbullet.bmp", true);
    loadBitmap(BITMAP_BULLET_ENEMY_BASIC, "./gfx/bullets/enemybasicbullet.bmp", true);
    loadBitmap(BITMAP_PLANE1_CENTRE, "./gfx/plane1/centre.bmp", true);
    loadBitmap(BITMAP_PLANE1_TILT_LEFT, "./gfx/plane1/tiltleft.bmp", true);
    loadBitmap(BITMAP_PLANE1_TILT_RIGHT, "./gfx/plane1/tiltright.bmp", true);
    loadBitmap(BITMAP_PLANE2_CENTRE, "./gfx/plane2/centre.bmp", true);
    loadBitmap(BITMAP_PLANE2_TILT_LEFT, "./gfx/plane2/tiltleft.bmp", true);
    loadBitmap(BITMAP_PLANE2_TILT_RIGHT, "./gfx/plane2/tiltright.bmp", true);
    loadBitmap(BITMAP_CLOUD1, "./gfx/clouds/cloud1.bmp", true);
    loadBitmap(BITMAP_CLOUD2, "./gfx/clouds/cloud2.bmp", true);
    loadBitmap(BITMAP_CLOUD3, "./gfx/clouds/cloud3.bmp", true);
    loadBitmap(BITMAP_CLOUD4, "./gfx/clouds/cloud4.bmp", true);
    loadBitmap(BITMAP_CLOUD5, "./gfx/clouds/cloud5.bmp", true);
    loadBitmap(BITMAP_CLOUD6, "./gfx/clouds/cloud6.bmp", true);
    loadBitmap(BITMAP_SHIELD_1, "./gfx/shield/shield1.bmp", true);
    loadBitmap(BITMAP_SHIELD_2, "./gfx/shield/shield2.bmp", true);
    loadBitmap(BITMAP_SHIELD_3, "./gfx/shield/shield3.bmp", true);
    loadBitmap(BITMAP_SHIELD_4, "./gfx/shield/shield4.bmp", true);
    loadBitmap(BITMAP_SCORE_BUBBLE_100, "./gfx/scorebubbles/100.bmp", true);
    loadBitmap(BITMAP_SCORE_BUBBLE_500, "./gfx/scorebubbles/500.bmp", true);
    loadBitmap(BITMAP_SCORE_BUBBLE_1000, "./gfx/scorebubbles/1000.bmp", true);
    loadBitmap(BITMAP_MISSION_TEXT1, "./gfx/missiontext/mission1.bmp", true);
    loadBitmap(BITMAP_MISSION_TEXT2, "./gfx/missiontext/mission2.bmp", true);
    loadBitmap(BITMAP_MISSION_TEXT3, "./gfx/missiontext/mission3.bmp", true);
    loadBitmap(BITMAP_MISSION_TEXT4, "./gfx/missiontext/mission4.bmp", true);
    loadBitmap(BITMAP_DIGIT0, "./gfx/digits/0.bmp", true);
    loadBitmap(BITMAP_DIGIT1, "./gfx/digits/1.bmp", true);
    loadBitmap(BITMAP_DIGIT2, "./gfx/digits/2.bmp", true);
    loadBitmap(BITMAP_DIGIT3, "./gfx/digits/3.bmp", true);
    loadBitmap(BITMAP_DIGIT4, "./gfx/digits/4.bmp", true);
    loadBitmap(BITMAP_DIGIT5, "./gfx/digits/5.bmp", true);
    loadBitmap(BITMAP_DIGIT6, "./gfx/digits/6.bmp", true);
    loadBitmap(BITMAP_DIGIT7, "./gfx/digits/7.bmp", true);
    loadBitmap(BITMAP_DIGIT8, "./gfx/digits/8.bmp", true);
    loadBitmap(BITMAP_DIGIT9, "./gfx/digits/9.bmp", true);
    loadBitmap(BITMAP_GAME_OVER_TEXT, "./gfx/missiontext/gameover.bmp", true);
    loadBitmap(BITMAP_TITLE, "./gfx/title/title.bmp", false);
    loadBitmap(BITMAP_POWERUP_EXTRA_LIFE, "./gfx/powerup/extralife.bmp", true);
    loadBitmap(BITMAP_POWERUP_SHIELD, "./gfx/powerup/shield.bmp", true);

    // Set initial colour to grey
    _colour = COLOUR_GREY;
}

void BitmapServer::shutdown() {
    for (Uint32 i = 0; i < BITMAP_TYPE_COUNT; i++) {
        SDL_FreeSurface(_surfaces[i]);
    }
}

void BitmapServer::loadBitmap(BitmapType type, const char* fileName, bool transparent) {
    // Load bitmap
    SDL_Surface* tmp;

    tmp = SDL_LoadBMP(fileName);
    _surfaces[type] = SDL_ConvertSurface(tmp, SDLTools::getScreen()->format, SDL_SWSURFACE);

    SDL_FreeSurface(tmp);

    // Set transparency
    if (transparent) {
        SDL_SetColorKey(_surfaces[type], SDL_SRCCOLORKEY, COLOUR_TRANSPARENT);
    }
}

void BitmapServer::changeColour(Uint32 newColour) {
    for (Uint32 i = 0; i < BITMAP_TYPE_COUNT; i++) {
        SDLTools::changeColour(_surfaces[i], _colour, newColour);
    }

    _colour = newColour;
}
