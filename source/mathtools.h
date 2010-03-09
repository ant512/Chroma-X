#ifndef _MATH_TOOLS_H_
#define _MATH_TOOLS_H_

#include <SDL/SDL.h>

/**
 * Class providing some optimised maths functions.
 */
class MathTools {
public:
	/**
	 * Get the sine of the supplied angle.
	 * @param angle The angle (in degrees) to find the sine of.
	 * @return The sine of the angle.  This value needs to be right-shifted
	 * 8 places to remove the fixed-point fractional value.
	 */
	static Sint16 sin(Sint16 angle);

	/**
	 * Get the cosine of the supplied angle.
	 * @param angle The angle (in degrees) to find the cosine of.
	 * @return The cosine of the angle.  This value needs to be right-shifted
	 * 8 places to remove the fixed-point fractional value.
	 */
	static Sint16 cos(Sint16 angle);

	/**
	 * Get the sine of the supplied angle.
	 * @param angle The angle (in degrees) to find the sine of.
	 * @return The sine of the angle.
	 */
	static Sint16 sinShifted(Sint16 angle);

	/**
	 * Get the cosine of the supplied angle.
	 * @param angle The angle (in degrees) to find the cosine of.
	 * @return The cosine of the angle.
	 */
	static Sint16 cosShifted(Sint16 angle);

	/**
	 * Calculate the angle and magnitude of velocity of the supplied components.
	 * @param speedX The x speed component.
	 * @param speedY The y speed component.
	 * @param angle Pointer to the angle value to set.
	 * @param magnitude Pointer to the magnitude to set.
	 */
    //static void convertToVector(Sint32 speedX, Sint32 speedY, Sint32* angle, Sint32* magnitude);

private:
	const static Sint16 _sineTable[512];
};

#endif
