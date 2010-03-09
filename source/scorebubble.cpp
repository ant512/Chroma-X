#include "scorebubble.h"

ScoreBubble::ScoreBubble(Sint32 x, Sint32 y, ScoreBubble::ScoreBubbleType type) {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());

    switch (type) {
        case SCORE_BUBBLE_100:
            ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_SCORE_BUBBLE_100);
            break;
        case SCORE_BUBBLE_500:
            ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_SCORE_BUBBLE_500);
            break;
        case SCORE_BUBBLE_1000:
            ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_SCORE_BUBBLE_1000);
            break;
    }

    _x = x;
    _y = y;
    _timer = 120;

    // Set up movement
    setMovementEngine(new BasicMovementEngine(0, -64, 0, 0));
}

ScoreBubble::~ScoreBubble() {
}

bool ScoreBubble::run() {
    GameSprite::run();

    // Count down until sprite should be killed
    if (_timer > 0) {
        _timer--;

        if (_timer == 0) {
            kill();
        }
    }

    return true;
}
