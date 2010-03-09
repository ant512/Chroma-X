#include "score.h"
#include "gamesprite.h"

// Initialise static variables
Uint32 Score::_score = 0;
Uint32 Score::_highScore = 0;
GameSprite* Score::_sprite = NULL;

Uint32 Score::getScore() {
	return _score;
}

Uint32 Score::getHighScore() {
	return _highScore;
}

void Score::add(Uint32 value) {
	_score += value;

	DigitWriter::draw(SCORE_X, SCORE_Y, _score, COLOUR_RED, true);

	// Is this the new high score?
	if (_score > _highScore) {
		_highScore = _score;
		DigitWriter::draw(HISCORE_X, HISCORE_Y, _highScore, COLOUR_RED, true);
	}
}

void Score::draw() {
    DigitWriter::draw(SCORE_X, SCORE_Y, _score, COLOUR_RED, true);
    DigitWriter::draw(HISCORE_X, HISCORE_Y, _highScore, COLOUR_RED, true);
}
