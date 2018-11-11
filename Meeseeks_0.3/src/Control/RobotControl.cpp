#include "RobotControl.h"
#include <GenericHID.h>
#include "..\MeeseeksProperties.h"

extern MeeseeksProperties g_mp;

RobotControl::RobotControl()
			: m_driveJoyStick(JOYSTICK_1)
{
	m_x = -10.0;
	m_y = -10.0;
	m_z = -10.0;

	m_lastX = 0.0;
	m_lastY = 0.0;
	m_lastZ = 0.0;

	m_bXYZChanged = false;
	m_rotationPoint = eRotateCenter;

	for (int index=1; index<=12; index++)
		m_lastButtonState[index] = false;
}

double RobotControl::Deadband(double input, double deadbandHalfWidth)
{
	double yInercept;

	if (input > deadbandHalfWidth)
		yInercept =  deadbandHalfWidth / (deadbandHalfWidth - 1.0);
	else if (input < -deadbandHalfWidth)
		yInercept = deadbandHalfWidth / (1.0 - deadbandHalfWidth);
	else
		return 0.0;

	double slope = 1.0/(1.0 - deadbandHalfWidth);

	return input * slope + yInercept;
}

bool RobotControl::Periodic()
{
	m_driveJoyStick.Periodic();

	m_x =  Deadband(m_driveJoyStick.GetX(), g_mp.m_deadbandX);
	m_y = -Deadband(m_driveJoyStick.GetY(), g_mp.m_deadbandY);
	m_z =  Deadband(m_driveJoyStick.GetZ(), g_mp.m_deadbandZ);

	if (m_driveJoyStick.OnlyX()->Pressed()) {
		m_y = 0.0;
		m_z = 0.0;
	}
	else if (m_driveJoyStick.OnlyY()->Pressed()) {
		m_x = 0.0;
		m_z = 0.0;
	}
	else if (m_driveJoyStick.OnlyZ()->Pressed()) {
		m_x = 0.0;
		m_y = 0.0;
	}

	if ((m_lastX != m_x) || (m_lastY != m_y) || (m_lastZ != m_z)) {
		m_bXYZChanged = true;
		m_lastX = m_x;
		m_lastY = m_y;
		m_lastZ = m_z;
	}
	else
		m_bXYZChanged = false;

	if (m_driveJoyStick.CenterCenter()->Pressed())
		m_rotationPoint = eRotateCenter;

	else if (m_driveJoyStick.FrontLeftCenter()->Pressed())
		m_rotationPoint = eRotateFrontLeft;

	else if (m_driveJoyStick.FrontRightCenter()->Pressed())
		m_rotationPoint = eRotateFrontRight;

	else if (m_driveJoyStick.BackLeftCenter()->Pressed())
		m_rotationPoint = eRotateBackLeft;

	else if (m_driveJoyStick.BackRightCenter()->Pressed())
		m_rotationPoint = eRotateBackRight;

	return m_bXYZChanged;
}

bool RobotControl::Grab()
{
	return m_driveJoyStick.Grab()->Value() != 0 ? true : false;
}

bool RobotControl::XYZChanged()
{
	return m_bXYZChanged;
}

double RobotControl::X()//Returns X value
{
	return m_x;
}

double RobotControl::Y()//Returns Y Value
{
	return m_y;
}

double RobotControl::Z()//Returns Z Value
{
	return m_z;
}

bool RobotControl::SetSteerOffsets()
{
	return m_driveJoyStick.SetSteerOffsets()->Pressed();
}

eRotationPoint RobotControl::RotationPoint()//Returns current point of rotation.
{
	return m_rotationPoint;
}
