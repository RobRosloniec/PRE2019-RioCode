#ifndef ROBOT_CONTROL_H_INCLUDED
#define ROBOT_CONTROL_H_INCLUDED

#include <wpilib.h>
#include "..\Joystick\DriveJoystick.h"
#include "..\Defines.h"

#define JOYSTICK_1	0

class RobotControl
{
	public    : RobotControl();

				bool Periodic();
				bool XYZChanged();

				double X();
				double Y();
				double Z();

				bool Grab();
				bool SetSteerOffsets();

				eRotationPoint RotationPoint();
	protected :
				double Deadband(double x, double d);

				DriveJoystick  m_driveJoyStick;
				eRotationPoint m_rotationPoint;
				double         m_x, m_y, m_z, m_lastX, m_lastY, m_lastZ;
				bool           m_lastButtonState[16];
				bool           m_bXYZChanged;
};

#endif
