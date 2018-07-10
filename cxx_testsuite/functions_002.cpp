#include "globals.h"
#include "functions_002.h"

int g_localSensorData;
int g_suppSensorData;

int* getNullSensor() {
	return nullptr;
}

int* getLowSensor() {
	return &g_localSensorData;
}

int* getHighSensor(int sensorNum) {
	if (sensorNum == 0) {
		return &g_localSensorData;
	}
	else {
		return &g_suppSensorData;
	}
	return nullptr;
}

void freeing_non_heap_memory_002_free(int * memory)
{
	delete[] memory;
}

int *xmalloc() {
	if (g_localSensorData) {
		return &g_localSensorData;
	}
	return 0;
}