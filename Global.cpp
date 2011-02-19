#include "Global.h"

Global *Global::myself = 0;

Global::Global(void) {
	static bool alreadyRun = false;
	
	if (!alreadyRun) {
		jLeft  = new Joystick(GLOBAL_JLEFT_PORT);
		jRight = new Joystick(GLOBAL_JRIGHT_PORT);

		ds = &DriverStation::GetInstance()->GetEnhancedIO();

		myself = this;
		
		alreadyRun = true;
	}

	printf("instantiated global\n"); 
}

Joystick* Global::GetLeftJoystick()  { return jLeft;  }
Joystick* Global::GetRightJoystick() { return jRight; }

bool Global::GetDigitalButton(int num) { return !(ds->GetDigital(num)); }

bool Global::GetAnalogButton(int num) {
	int j;
	for (j = 1; j <= 8; j++) {
		if (ds->GetAnalogIn(j) <= 0.01) {
			return (j == num);
		}
	}

	return 0;
}

Global* Global::GetInstance() {
	return myself;
}

