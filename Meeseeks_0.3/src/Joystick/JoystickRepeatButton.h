#ifndef SRC_JOYSTICKREPEATBUTTON_H_
#define SRC_JOYSTICKREPEATBUTTON_H_

#include "JoystickValueButton.h"
#include <Timer.h>

class JoystickRepeatButton : public JoystickValueButton
{
public :
	JoystickRepeatButton(int index, int valueCount, int initialValue = 0,
			bool bLoop = false, int delta = 1, double dwellTime = 1.0, double updateRate = 1.0);
private :
	bool Update(bool bPressed);

	Timer m_timer;
	double m_dwellTime, m_waitTime, m_lastUpdateTime;
	bool m_bWaitingForDwell;
};

#endif /* SRC_JOYSTICKREPEATBUTTON_H_ */
