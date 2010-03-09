#ifndef _GAME_H_
#define _GAME_H_

#include <SDL/SDL.h>
#include "constants.h"
#include "particlemanager.h"
#include "bulletmanager.h"
#include "sdltools.h"
#include "bitmapserver.h"
#include "playermovementengine.h"
#include "enemymanager.h"
#include "spritemanager.h"
#include "soundplayer.h"
#include "level.h"
#include "cloudmanager.h"

class Chopper;

/**
 * Class containing all game functionality.
 */
class Game {
public:

	/**
	 * Get a pointer to the particle manager.
	 * @return Pointer to the particle manager.
	 */
    static ParticleManager* getParticleManager();

	/**
	 * Get a pointer to the player bullet manager.
	 * @return Pointer to the player bullet manager.
	 */
    static BulletManager* getPlayerBulletManager();

	/**
	 * Get a pointer to the enemy bullet manager.
	 * @return Pointer to the enemy bullet manager.
	 */
    static BulletManager* getEnemyBulletManager();

	/**
	 * Get a pointer to the sprite manager.  The sprite manager
	 * contains a list of non-interactive sprites such as score
	 * bubbles.
	 * @return Pointer to the sprite manager.
	 */
    static SpriteManager* getSpriteManager();

	/**
	 * Get a pointer to the enemy manager.
	 * @return Pointer to the enemy manager.
	 */
    static EnemyManager* getEnemyManager();

    /**
     * Get a pointer to the player.
     * @return Pointer to the player.
     */
    static Chopper* getPlayer();

	/**
	 * Run the game.
	 */
    static void run();

    /**
     * Redraw the background image.
     */
    static void redrawBackground();

    /**
     * Game over!
     */
    static void gameOver();

private:
    static ParticleManager* _particleManager;
    static GameSprite* _background;
    static Chopper* _player;
    static BulletManager* _playerBulletManager;
    static BulletManager* _enemyBulletManager;
    static EnemyManager* _enemyManager;
    static SpriteManager* _spriteManager;
    static Level* _level;
    static CloudManager* _cloudManager;
    static bool _gameOver;

	/**
	 * Initialise the game.
	 */
    static void init();

	/**
	 * The main game loop.
	 */
    static void mainLoop();

	/**
	 * Shut down the game.
	 */
    static void quit();

	/**
	 * Blank the screen.
	 */
    static void clearPlayfield();
};

#endif
