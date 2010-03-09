#ifndef _CLOUD_MANAGER_H_
#define _CLOUD_MANAGER_H_

#include <SDL/SDL.h>
#include <vector>
#include "constants.h"

// Avoid cyclic dependencies by defining game sprite class
class Cloud;

/**
 * Class to manage sprites
 */
class CloudManager {
public:
	/**
	 * Constructor.
	 */
    CloudManager();

	/**
	 * Destructor.
	 */
    ~CloudManager();

	/**
	 * Add a new cloud.
	 * @param randomY If set to true, the cloud appears at a random Y co-ordinate.
	 * If set to false, the cloud appears off-screen.
	 */
    void add(bool randomY);

	/**
	 * Run the sprite manager.  Should be called every frame.
	 */
    void run();

private:
    std::vector<Cloud*> _sprites;
};

#endif
