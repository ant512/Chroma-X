#include "soundplayer.h"

Mix_Chunk* SoundPlayer::_sounds[SOUND_TYPE_COUNT];
Uint32 SoundPlayer::_volume = 60;

void SoundPlayer::init() {

    // Initialize SDL_mixer

    #ifdef PLATFORM_GP2X

    // Use smaller buffer for the 2X to prevent sound lag
    Mix_OpenAudio(22050, AUDIO_S16, MIX_DEFAULT_CHANNELS, 128);

    #else

    // SDL_mixer sucks in Windows no matter what I do, so
    // we may as well have good playback even if it is delayed
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_S16, MIX_DEFAULT_CHANNELS, 512);

    #endif

    // Set volume
    Mix_Volume(-1, _volume);

    // Load samples
    _sounds[SOUND_LASER_1] = Mix_LoadWAV("./sfx/laser1.wav");
    _sounds[SOUND_LASER_2] = Mix_LoadWAV("./sfx/laser2.wav");
    _sounds[SOUND_EXPLOSION_1] = Mix_LoadWAV("./sfx/explosion1.wav");
    _sounds[SOUND_CLANK_1] = Mix_LoadWAV("./sfx/clank1.wav");
    _sounds[SOUND_MACHINE_GUN_1] = Mix_LoadWAV("./sfx/machinegun1.wav");
}

void SoundPlayer::play(SoundPlayer::SoundType sound) {
	Mix_PlayChannel(-1, _sounds[sound], 0);
}

void SoundPlayer::play(SoundPlayer::SoundType sound, Uint32 channel) {
	Mix_PlayChannel(channel, _sounds[sound], 0);
}

void SoundPlayer::shutdown() {
    for (Uint32 i = 0; i < SOUND_TYPE_COUNT; i++) {
        Mix_FreeChunk(_sounds[i]);
    }

    Mix_CloseAudio();
}

void SoundPlayer::run() {
    // Volume control

    Sint32 volumeDelta = 0;

    #ifdef PLATFORM_GP2X

    // GP2X volume buttons
    if (SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_VOLUP)) {
        volumeDelta++;
    } else if (SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_VOLDOWN)) {
        volumeDelta--;
    }

    #else

    // Keyboard
    Uint8* keyState = SDL_GetKeyState(NULL);

    if (keyState[SDLK_PAGEUP]) {
        volumeDelta++;
    } else if (keyState[SDLK_PAGEDOWN]) {
        volumeDelta--;
    }

    #endif

    // Change volume
    if ((volumeDelta == -1) && (_volume >= 1)) {
        _volume += volumeDelta;
        Mix_Volume(-1, _volume);
    } else if ((volumeDelta == 1) && (_volume < 128)) {
        _volume += volumeDelta;
        Mix_Volume(-1, _volume);
    }
}
