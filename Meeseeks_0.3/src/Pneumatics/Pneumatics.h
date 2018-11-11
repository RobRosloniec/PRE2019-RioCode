#ifndef PNEUMATICS_H_INCLUDED
#define PNEUMATICS_H_INCLUDED

#include <wpilib.h>

class Pneumatics
{
	public    : Pneumatics();

				void Grab(bool bGrab);
	protected :
				DoubleSolenoid m_doubleSolonoid;
};

#endif
