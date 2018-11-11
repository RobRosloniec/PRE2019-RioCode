#include "Robot.h"
#include "MeeseeksProperties.h"
#include "DataTable\TableController.h"

TableController    g_tc;
MeeseeksProperties g_mp;

void Robot::RobotInit()
{
	g_mp.Initialize();

	g_tc.Initialize();

	m_gyro.Initialize();

	m_swerve.Initialize();
}

void Robot::TeleopInit()
{
	m_gyro.ZeroYaw();
}

void Robot::TeleopPeriodic()
{
	if (m_control.Periodic())
		m_swerve.Drive(m_control.X(), m_control.Y(), m_control.Z(), m_gyro.Yaw(), m_control.RotationPoint());

	m_pneumatics.Grab(m_control.Grab());

	m_swerve.Periodic();

	if (m_control.SetSteerOffsets())
		m_swerve.SetSteerOffsets();
}

void Robot::AutonomousInit()
{
}

void Robot::AutonomousPeriodic()
{
	m_swerve.Periodic();
}

START_ROBOT_CLASS(Robot)
