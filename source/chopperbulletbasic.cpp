#include "chopperbulletbasic.h"

ChopperBulletBasic::ChopperBulletBasic() {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());
    ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_BULLET_CHOPPER_BASIC);

    // Set up movement
    setMovementEngine(new BasicMovementEngine(0, -3 << 8, 0, 0));

    // Set other properties
    _width = ((BitmapRenderEngine*)_renderEngine)->getWidth();
    _height = ((BitmapRenderEngine*)_renderEngine)->getHeight();
}

ChopperBulletBasic::~ChopperBulletBasic() {
}
