#ifndef SWERVE_DRIVE_H_INCLUDED
#define SWERVE_DRIVE_H_INCLUDED

#include <SwerveDrive/SwerveModule.h>
#include <wpilib.h>
#include "Defines.h"

#define BACK_LEFT_STEER   2
#define BACK_LEFT_DRIVE   3
#define FRONT_LEFT_STEER  4
#define FRONT_LEFT_DRIVE  5
#define BACK_RIGHT_STEER  6
#define BACK_RIGHT_DRIVE  7
#define FRONT_RIGHT_STEER 8
#define FRONT_RIGHT_DRIVE 9


class SwerveDrive
{
	public    : SwerveDrive();

				void Initialize();
				int  Drive(double x, double y, double z, double yaw, eRotationPoint rotationPoint);
				void Periodic();
				void SetSteerOffsets();
	protected :
				void RectangularToBoundedCircle(double &x, double &y);
				void RotateCorners(double rotation, eRotationPoint rotationPoint, DoubleXY *pDestRect);
				void TransformRotatedCorners(double x, double y, double yaw, DoubleXY *pSource, DoubleXY *pDest);
				void CalculateDriveVectors(DoubleXY *pDestCorners);

				SwerveModule *m_module[4];
				double        m_angle[4], m_magnitude[4];
};

#endif
