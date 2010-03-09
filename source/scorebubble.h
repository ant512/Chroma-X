#ifndef _SCORE_BUBBLE_H_
#define _SCORE_BUBBLE_H_

#include "bitmaprenderengine.h"
#include "basicmovementengine.h"

/**
 * Score bubble class.
 */
class ScoreBubble : public GameSprite {
public:

    /**
     * List of available scores.
     */
    enum ScoreBubbleType {
        SCORE_BUBBLE_100 = 0,
        SCORE_BUBBLE_500 = 1,
        SCORE_BUBBLE_1000 = 2
    };

    /**
     * Constructor.
     */
    ScoreBubble(Sint32 x, Sint32 y, ScoreBubbleType type);

    /**
     * Destructor
     */
    ~ScoreBubble();

	/**
	 * Perform all main loop operations for this sprite.
	 * @return True if the function completed all operations successfully.
	 */
	bool run();

private:
    Sint32 _timer;
};

#endif
