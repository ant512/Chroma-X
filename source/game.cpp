#include "game.h"
#include "chopper.h"
#include "missiontext.h"

// Initialise static members
GameSprite* Game::_background = NULL;
ParticleManager* Game::_particleManager = NULL;
Chopper* Game::_player = NULL;
BulletManager* Game::_playerBulletManager = NULL;
BulletManager* Game::_enemyBulletManager = NULL;
EnemyManager* Game::_enemyManager = NULL;
SpriteManager* Game::_spriteManager = NULL;
Level* Game::_level = NULL;
CloudManager* Game::_cloudManager = NULL;
bool Game::_gameOver = false;

void Game::init() {

    // Initialise particle manager
    if (_particleManager == NULL) {
        _particleManager = new ParticleManager();
    }

    // Initialise player
    if (_player == NULL) {
        _player = new Chopper();
    }

    // Initialise player bullet manager
    if (_playerBulletManager == NULL) {
        _playerBulletManager = new BulletManager();
    }

    // Initialise enemy bullet manager
    if (_enemyBulletManager == NULL) {
        _enemyBulletManager = new BulletManager();
    }

    // Initialise enemy manager
    if (_enemyManager == NULL) {
        _enemyManager = new EnemyManager();
    }

    // Initialise sprite manager
    if (_spriteManager == NULL) {
        _spriteManager = new SpriteManager();
    }

    // Initialise cloud manager
    if (_cloudManager == NULL) {
        _cloudManager = new CloudManager();
    }

    // Initialise level
    if (_level == NULL) {
        _level = new Level();
    }

    // Load background
    _background = new GameSprite();
    _background->setRenderEngine(new BitmapRenderEngine());
    ((BitmapRenderEngine*)_background->getRenderEngine())->setBitmap(BitmapServer::BITMAP_GAME_BACKGROUND);
    ((BitmapRenderEngine*)_background->getRenderEngine())->setClipping(false);
    _background->run();

    // Update screen
    SDL_UpdateRect(SDLTools::getScreen(), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    _gameOver = false;
}

ParticleManager* Game::getParticleManager() {
    return _particleManager;
}

BulletManager* Game::getPlayerBulletManager() {
    return _playerBulletManager;
}

BulletManager* Game::getEnemyBulletManager() {
    return _enemyBulletManager;
}

SpriteManager* Game::getSpriteManager() {
    return _spriteManager;
}

EnemyManager* Game::getEnemyManager() {
    return _enemyManager;
}

Chopper* Game::getPlayer() {
    return _player;
}

void Game::run() {
    init();
    mainLoop();
    quit();
}

void Game::clearPlayfield() {

    // Clear the screen to white
    SDL_Rect rect;
    rect.x = PLAYFIELD_X;
    rect.y = PLAYFIELD_Y;
    rect.w = PLAYFIELD_WIDTH;
    rect.h = PLAYFIELD_HEIGHT;
    SDL_FillRect(SDLTools::getScreen(), &rect, COLOUR_WHITE);
}

void Game::mainLoop() {
    bool running = true;
    SDL_Event event;

    while(running) {

        clearPlayfield();

        // Handle clouds
        _cloudManager->run();

        // Handle particles
        _particleManager->run();

        // Handle non-interactive sprites
        _spriteManager->run();


        if (!_gameOver) {

            // Handle player bullets
            _playerBulletManager->run();

            // Handle enemy bullets
            _enemyBulletManager->run();

            // Handle enemies
            _enemyManager->run();

            // Run the player
            _player->run();

            // Run the level
            _level->run();
        }

        // Handle the sound player		// Check user input and other events
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        SoundPlayer::run();

        // Update the screen
        SDL_UpdateRect(SDLTools::getScreen(), PLAYFIELD_X, PLAYFIELD_Y, PLAYFIELD_WIDTH, PLAYFIELD_HEIGHT);

        SDL_Delay(10);

		// Check user input and other events
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
    }
}

void Game::quit() {
    delete _particleManager;
    delete _playerBulletManager;
    delete _enemyBulletManager;
    delete _player;
    delete _enemyManager;
    delete _level;
    delete _cloudManager;
}

void Game::redrawBackground() {
    _background->run();

    // Update the screen
    SDL_UpdateRect(SDLTools::getScreen(), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Game::gameOver() {
    // Flush everything from the sprite manager
    _spriteManager->clear();

    _spriteManager->add(new MissionText(5));
    _gameOver = true;
}
