#include "digitwriter.h"
#include "gamesprite.h"

// Initialise static variables
GameSprite* DigitWriter::_sprite = NULL;

void DigitWriter::draw(Sint32 x, Sint32 y, Uint32 value, Uint32 backgroundColour, bool erase) {
    // Ensure sprite exists
    if (_sprite == NULL) {
        _sprite = new GameSprite();
        _sprite->setRenderEngine(new BitmapRenderEngine());
        ((BitmapRenderEngine*)_sprite->getRenderEngine())->setBitmap(BitmapServer::BITMAP_DIGIT0);
        ((BitmapRenderEngine*)_sprite->getRenderEngine())->setClipping(false);
    }

    // Move to correct y location
    _sprite->setY(y);

    // Get pointer to renderer
    BitmapRenderEngine* renderer = (BitmapRenderEngine*)_sprite->getRenderEngine();

    // Prepare rect for erasing old value
    SDL_Rect rect;
    rect.y = y;
    rect.h = renderer->getSurface()->h;
    rect.w = renderer->getSurface()->w;

    Uint32 valuePart = 0;
    Uint32 totalWidth = rect.w;

    // Draw individual digits
    while (value > 0) {
        valuePart = value % 10;
        value /= 10;

        // Update erase rect
        rect.x = x;

        // Move sprite to correct x location
        _sprite->setX(x);

        // Erase old value
        if (erase) {
            SDL_FillRect(SDLTools::getScreen(), &rect, backgroundColour);
        }

        // Which bitmap should we use?
        switch (valuePart) {
            case 0:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT0);
                break;
            case 1:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT1);
                break;
            case 2:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT2);
                break;
            case 3:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT3);
                break;
            case 4:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT4);
                break;
            case 5:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT5);
                break;
            case 6:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT6);
                break;
            case 7:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT7);
                break;
            case 8:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT8);
                break;
            case 9:
                renderer->setBitmap(BitmapServer::BITMAP_DIGIT9);
                break;
        }

        _sprite->run();

        x -= rect.w;
        totalWidth += rect.w;
    }

    // Update the screen
    SDL_UpdateRect(SDLTools::getScreen(), x, y, totalWidth, rect.h);
}
