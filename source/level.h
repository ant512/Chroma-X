#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <SDL/SDL.h>

class Level {
public:
    /**
     * Constructor.
     */
    Level();

    /**
     * Destructor.
     */
    ~Level();

    /**
     * Main function; should be called every frame.
     */
    void run();

    /**
     * Level 1 script.
     */
    void level1();

    /**
     * Level 2 script.
     */
    void level2();

    /**
     * Level 3 script.
     */
    void level3();

    /**
     * Level 4 script.
     */
    void level4();

    /**
     * Add a Plane1 enemy to the game.
     * @param x The x co-ordinate of the plane.
     */
    void addPlane1(Sint32 x);

    /**
     * Add a Plane2 enemy to the game.
     * @param x The x co-ordinate of the plane.
     */
    void addPlane2(Sint32 x);

    /**
     * Add a UFO enemy to the game.
     * @param x The x co-ordinate of the ufo.
     */
    void addUFO(Sint32 x);

    /**
     * Add a rocket enemy to the game.
     * @param x The x co-ordinate of the rocket.
     */
    void addRocket(Sint32 x);

    /**
     * Add text announcing the start of a level to the game.
     */
    void addMissionText();

protected:
    Uint32 _distance;
    Uint32 _level;

    /**
     * Add random rockets to the level.
     */
    void level1RocketStorm();
};

#endif
