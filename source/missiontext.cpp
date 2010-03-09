#include "missiontext.h"

MissionText::MissionText(Uint32 level) {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());

    BitmapServer::BitmapType type = BitmapServer::BITMAP_MISSION_TEXT1;
    switch (level) {
        case 1:
            type = BitmapServer::BITMAP_MISSION_TEXT1;
            break;
        case 2:
            type = BitmapServer::BITMAP_MISSION_TEXT2;
            break;
        case 3:
            type = BitmapServer::BITMAP_MISSION_TEXT3;
            break;
        case 4:
            type = BitmapServer::BITMAP_MISSION_TEXT4;
            break;
        case 5:
            type = BitmapServer::BITMAP_GAME_OVER_TEXT;
            break;
    }
    ((BitmapRenderEngine*)_renderEngine)->setBitmap(type);

    setY(PLAYFIELD_HEIGHT);
    setX(PLAYFIELD_X + (PLAYFIELD_WIDTH / 2) - (getWidth() / 2));

    // Set up movement
    setMovementEngine(new MissionTextMovementEngine());
}

MissionText::~MissionText() {
}
