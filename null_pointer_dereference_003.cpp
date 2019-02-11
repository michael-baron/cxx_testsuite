/*
Emenda Ltd, 02/05/2018
Null Pointer Dereference
*/

#include "globals.h"

void null_pointer_dereference_003_P() {
	int *p = nullptr;
	if (g_suppSensorData == 1) {
		p = &g_localSensorData;
	}
	*p = 1; //DEFECT
}
