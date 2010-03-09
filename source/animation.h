#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <SDL/SDL.h>
#include <vector>
#include "bitmapserver.h"

/**
 * Class for creating sequences of bitmaps.
 */
class Animation {
public:
	/**
	 * Animation status enum.
	 */
	enum Status {
		ANIMATION_STATUS_STOPPED = 0,	/**< Animation has stopped */
		ANIMATION_STATUS_PLAYING = 1,	/**< Animation is playing */
		ANIMATION_STATUS_PAUSED = 2		/**< Animation has been paused */
	};

	/**
	 * Animation loop type enum.
	 */
	enum LoopType {
		ANIMATION_LOOPTYPE_NONE = 0,	/**< Animation will not loop */
		ANIMATION_LOOPTYPE_LOOP = 1,	/**< Animation will loop */
		ANIMATION_LOOPTYPE_PINGPONG = 2	/**< Animation will loop ping-pong style */
	};

	/**
	 * Struct defining a single animation frame.
	 */
	typedef struct {
		SDL_Surface* surface;
		Uint8 delay;
	} AnimFrame;

	/**
	 * Constructor
	 */
	Animation(const Uint8 speed, const LoopType loopType, const Uint16 loops);

	/**
	 * Destructor
	 */
	~Animation();

	// Getters
	const AnimFrame* getCurrentFrame() const;
	SDL_Surface* getCurrentSurface() const;
	const Status getStatus() const;
	const Uint8 getSpeed() const;
	const LoopType getLoopType() const;
	const Uint16 getTimeToNextFrame() const;
	const Uint16 getFrameCount() const;

	// Setters
	void setSpeed(const Uint8 speed);
	void setLoopType(const LoopType loopType);

    /**
     * Add a new frame to the animation.
     * @param type type The type of the bitmap to add.
     * @param delay A frame-specific delay to add on to the standard display
     * time for this frame.
     */
	void addFrame(BitmapServer::BitmapType type, const Uint8 delay);

	// Playback control
	void run();
	void play();
	void stop();
	void pause();
	void goToFrame(Uint16 frame);

private:
	std::vector<AnimFrame> _frames;
	Uint8 _speed;
	Uint16 _frameTimer;
	Uint16 _currentFrame;
	Sint8 _frameInc;
	Uint16 _requestedLoops;
	Uint16 _loopCount;

	LoopType _loopType;
	Status _status;

	bool loop();
};

#endif
