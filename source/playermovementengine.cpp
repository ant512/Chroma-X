#include "playermovementengine.h"

PlayerMovementEngine::PlayerMovementEngine() {
    _pad.left = false;
    _pad.right = false;
    _pad.up = false;
    _pad.down = false;

    _xSpeed = 0;
    _ySpeed = 0;
    _xAcceleration = 32;//64;
    _yAcceleration = 32;
    _maxSpeed = 384;//512;
}

PlayerMovementEngine::~PlayerMovementEngine() {
}

bool PlayerMovementEngine::move() {

    // Get sprite co-ordinates
    Sint32 x = _sprite->getShiftedX();
    Sint32 y = _sprite->getShiftedY();

    Sint32 shiftedX = 0;
    Sint32 shiftedY = 0;

    updatePad();

    // Adjust speed based on pad state
    if (_pad.up) {
        // Accelerate up
        _ySpeed -= _yAcceleration;
    } else if (_pad.down) {
        // Accelerate down
        _ySpeed += _yAcceleration;
    } else if (_ySpeed > 0) {
        // Decelerate travelling down
        _ySpeed -= _yAcceleration;
    } else if (_ySpeed < 0) {
        // Decelerate travelling up
        _ySpeed += _yAcceleration;
    }

    if (_pad.left) {
        // Accelerate left
       _xSpeed -= _xAcceleration;
    } else if (_pad.right) {
        // Accelerate right
       _xSpeed += _xAcceleration;
    } else if (_xSpeed > 0) {
        // Decelerate travelling right
        _xSpeed -= _xAcceleration;
    } else if (_xSpeed < 0) {
        // Decelerate travelling left
        _xSpeed += _xAcceleration;
    }

    // Limit speed
    if (_xSpeed > _maxSpeed) {
        _xSpeed = _maxSpeed;
    } else if (_xSpeed < -_maxSpeed) {
        _xSpeed = -_maxSpeed;
    }

    if (_ySpeed > _maxSpeed) {
        _ySpeed = _maxSpeed;
    } else if (_ySpeed < -_maxSpeed) {
        _ySpeed = -_maxSpeed;
    }

    // Update co-ordinates
    x += _xSpeed;
    y += _ySpeed;

    // Get shifted versions of co-ordinates for boundary checking
    shiftedX = x >> 8;
    shiftedY = y >> 8;

    // Limit to screen position
    if (shiftedX < PLAYFIELD_X) {
        x = PLAYFIELD_X << 8;
        _xSpeed = 0;
    } else if (shiftedX + _sprite->getWidth() > PLAYFIELD_X + PLAYFIELD_WIDTH) {
        x = (PLAYFIELD_X + PLAYFIELD_WIDTH - _sprite->getWidth()) << 8;
        _xSpeed = 0;
    }

    if (shiftedY < PLAYFIELD_Y) {
        y = PLAYFIELD_Y << 8;
        _ySpeed = 0;
    } else if (shiftedY + _sprite->getHeight() > PLAYFIELD_Y + PLAYFIELD_HEIGHT) {
        y = (PLAYFIELD_Y + PLAYFIELD_HEIGHT - _sprite->getHeight()) << 8;
        _ySpeed = 0;
    }

    // Update sprite
    _sprite->setShiftedX(x);
    _sprite->setShiftedY(y);

    return true;
}

void PlayerMovementEngine::updatePad() {
    // Handle controls
    #ifdef PLATFORM_GP2X

    // GP2X pad
    _pad.up = SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_UP) |
              SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_UPLEFT) |
              SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_UPRIGHT);

    _pad.down = SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_DOWN) |
                SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_DOWNLEFT) |
                SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_DOWNRIGHT);

    _pad.left = SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_LEFT) |
                SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_UPLEFT) |
                SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_DOWNLEFT);

    _pad.right = SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_RIGHT) |
                 SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_UPRIGHT) |
                 SDL_JoystickGetButton(SDLTools::getJoystick(), GP2X_BUTTON_DOWNRIGHT);
    #else

    // Keyboard
    Uint8* keyState = SDL_GetKeyState(NULL);
    _pad.up = keyState[SDLK_UP];
    _pad.down = keyState[SDLK_DOWN];
    _pad.left = keyState[SDLK_LEFT];
    _pad.right = keyState[SDLK_RIGHT];

    #endif
}

const PlayerMovementEngine::Pad* PlayerMovementEngine::getPad() const {
    return &_pad;
}
