#include "Global.h"

Global *Global::myself = 0;

Global::Global(void) {
	static bool alreadyRun = false;
	
	if (!alreadyRun) {
		if (GLOBAL_JLEFT_EXISTS)  jLeft  = new Joystick(GLOBAL_JLEFT_PORT);
		if (GLOBAL_JRIGHT_EXISTS) jRight = new Joystick(GLOBAL_JRIGHT_PORT);

		myself = this;
		
		alreadyRun = true;
	}
}

Joystick* Global::GetJLeft()  { return jLeft;  }
Joystick* Global::GetJRight() { return jRight; }

Global* Global::GetInstance() {
	return myself;
}
