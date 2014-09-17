/**
 * Description: Definitions for the finite state machine.
 */

#include "fanRemote.h"


enum state
{
	OFF,
	SPEED1,
	SPEED2,
	SPEED3
};


enum trigger
{
	T_POWER = POWER,
	T_A = A,
	T_B = B,
	T_C = C
};


enum effect
{
	SPEED0_OFF,
	SPEED3_FORWARD,
	SPEED2_FORWARD,
	SPEED1_FORWARD,
	SPEED2_BACKWARD,
	SPEED3_BACKWARD
};
