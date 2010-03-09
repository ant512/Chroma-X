#ifndef _SCORE_H_
#define _SCORE_H_

#include <SDL/SDL.h>
#include "bitmaprenderengine.h"
#include "digitwriter.h"

class GameSprite;

class Score {
public:

	/**
	 * Get the player's score.
	 * @return The player's score.
	 */
	static Uint32 getScore();

	/**
	 * Get the high score.
	 */
	static Uint32 getHighScore();

	/**
	 * Increase the score by the specified amount.  Updates the
	 * high score if the current score is larger.
	 * @param value The value to increase the score by.
	 */
	static void add(Uint32 value);

	/**
	 * Output the score to the screen.
	 */
    static void draw();

private:
	static Uint32 _score;
	static Uint32 _highScore;
	static GameSprite* _sprite;
};

#endif
