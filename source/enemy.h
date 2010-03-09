#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <SDL/SDL.h>
#include "gamesprite.h"
#include "score.h"
#include "game.h"
#include "soundplayer.h"
#include "scorebubble.h"

/**
 * Basic enemy class.
 */
class Enemy : public GameSprite {
public:
	/**
	 * Constructor
	 */
	Enemy();

	/**
	 * Destructor
	 */
	~Enemy();

	/**
	 * Executed when the enemy is shot - increases player score,
	 * creates an explosion, drops a powerup if necessary.
	 */
	virtual void explode();

    /**
     * Create a new powerup if _dropPowerup is set to true.
     */
    virtual void createPowerup();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	virtual bool run();

	/**
	 * Set the score given when the enemy is killed.
	 * @param score The score.
	 */
    void setKillScore(Uint32 score);

    /**
     * Set the enemy's shield strength (number of shots needed to destroy it).
     * @param shots Number of shots needed to kill the enemy.
     */
    void setShieldStrength(Uint32 shots);

    /**
     * Set to true to make the enemy drop a powerup when killed.
     * @param dropPowerup True to drop a powerup.
     */
    void setDropPowerup(bool dropPowerup);

protected:
	Uint32 _killScore;
	Sint32 _shieldStrength;
	Uint32 _skipDrawFrames;
	bool _dropPowerup;

};

#endif
