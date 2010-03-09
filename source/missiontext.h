#ifndef _MISSION_TEXT_H_
#define _MISSION_TEXT_H_

#include "bitmaprenderengine.h"
#include "missiontextmovementengine.h"
#include "gamesprite.h"

/**
 * Mission text class.
 */
class MissionText : public GameSprite {
public:

    /**
     * Constructor.
     * @param level The level this text is for
     */
    MissionText(Uint32 level);

    /**
     * Destructor
     */
    ~MissionText();
};

#endif
