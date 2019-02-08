/*
Emenda Ltd, 02/05/2018
Null Pointer Dereference
*/

#include "functions_001.h"

void null_pointer_dereference_004_P(int sensorNum) {
	int *p = returnSensorData(sensorNum);
	*p = 1; //DEFECT
}

