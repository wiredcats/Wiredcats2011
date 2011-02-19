#include "Global.h"

Global *Global::myself = 0;

Global::Global(void) {
	static bool alreadyRun = false;
	
	if (!alreadyRun) {
		jLeft  = new Joystick(GLOBAL_JLEFT_PORT);
		jRight = new Joystick(GLOBAL_JRIGHT_PORT);

		myself = this;
		
		alreadyRun = true;
	}

	printf("instantiated global\n"); 
}

Joystick* Global::GetLeftJoystick()  { return jLeft;  }
Joystick* Global::GetRightJoystick() { return jRight; }

Global* Global::GetInstance() {
	return myself;
}
