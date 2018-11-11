#ifndef SRC_DRIVEJOYSTICK_H_
#define SRC_DRIVEJOYSTICK_H_

#include "MeeseeksJoystick.h"

class DriveJoystick : public MeeseeksJoystick
{
	public    : DriveJoystick(int joyStickPort);

				JoystickValueButton  *Grab()             { return &m_grab;             }
				JSButton             *FrontLeftCenter()  { return &m_frontLeftCenter;  }
				JSButton             *FrontRightCenter() { return &m_frontRightCenter; }
				JSButton             *BackLeftCenter()   { return &m_backLeftCenter;   }
				JSButton             *BackRightCenter()  { return &m_backRightCenter;  }
				JSButton             *CenterCenter()     { return &m_centerCenter;     }
				JSButton             *SetSteerOffsets()  { return &m_setSteerOffsets;  }
				JSButton			 *OnlyX()			 { return &m_onlyX;			   }
				JSButton			 *OnlyY()			 { return &m_onlyY;			   }
				JSButton			 *OnlyZ()			 { return &m_onlyZ;			   }

				void Periodic();
	protected :
				JoystickValueButton  m_grab;
				JSButton             m_frontLeftCenter, m_frontRightCenter, m_backLeftCenter, m_backRightCenter, m_centerCenter, m_setSteerOffsets;
				JSButton			 m_onlyX, m_onlyY, m_onlyZ;
};

#endif /* SRC_DRIVEJOYSTICK_H_ */
