#include "titlescreen.h"

void TitleScreen::draw() {
    // Draw the title screen
    GameSprite* title = new GameSprite();
    title->setRenderEngine(new BitmapRenderEngine());
    ((BitmapRenderEngine*)title->getRenderEngine())->setBitmap(BitmapServer::BITMAP_TITLE);
    ((BitmapRenderEngine*)title->getRenderEngine())->setClipping(false);
    title->run();
    delete title;

    // Update the screen
    SDL_UpdateRect(SDLTools::getScreen(), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void TitleScreen::run() {
    draw();
    wait();
}

void TitleScreen::wait() {

    // Check user input and other events
    bool next = false;
    SDL_Event event;

    while (!next) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    next = true;
                    break;
                case SDL_JOYBUTTONDOWN:
                    switch (event.jbutton.button) {
                        case GP2X_BUTTON_START:
                            next = true;
                            break;
                    }
            }
        }
    }
}
