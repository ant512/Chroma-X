#ifndef _SOUND_PLAYER_H_
#define _SOUND_PLAYER_H_

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <vector>
#include "constants.h"
#include "sdltools.h"

const Uint32 SOUND_TYPE_COUNT = 5;

/**
 * Class providing easy playback of pre-loaded sounds.
 */
class SoundPlayer {
public:

    /**
     * Sound types enum.
     */
    enum SoundType {
        SOUND_LASER_1 = 0,
        SOUND_LASER_2 = 1,
        SOUND_EXPLOSION_1 = 2,
        SOUND_CLANK_1 = 3,
        SOUND_MACHINE_GUN_1 = 4
    };

    /**
     * Initialise the sound player.
     */
    static void init();

    /**
     * Shutdown the sound player.
     */
    static void shutdown();

    /**
     * Play a sound.
     * @param sound The sound to play.
     */
    static void play(SoundType sound);

    /**
     * Play a sound on a specific channel
     * @param sound The sound to play.
     * @param channel The channel to play the sound on.
     */
    static void play(SoundType sound, Uint32 channel);

    /**
     * Sound code that should be run every frame - watches volume buttons
     */
    static void run();

private:
    static Mix_Chunk* _sounds[SOUND_TYPE_COUNT];
    static Uint32 _volume;
};

#endif
