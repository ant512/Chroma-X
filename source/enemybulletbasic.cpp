#include "enemybulletbasic.h"

EnemyBulletBasic::EnemyBulletBasic() {
    // Set up renderer
    setRenderEngine(new BitmapRenderEngine());
    ((BitmapRenderEngine*)_renderEngine)->setBitmap(BitmapServer::BITMAP_BULLET_ENEMY_BASIC);

    // Set up movement
    setMovementEngine(new BasicMovementEngine(0, 2 << 8, 0, 0));

    // Set other properties
    _width = ((BitmapRenderEngine*)_renderEngine)->getWidth();
    _height = ((BitmapRenderEngine*)_renderEngine)->getHeight();
}

EnemyBulletBasic::~EnemyBulletBasic() {
}
