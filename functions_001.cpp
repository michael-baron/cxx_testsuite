#include "functions_001.h"
#include "functions_002.h"
#include <stdlib.h>

int * returnSensorData(int sensorNum) {
	if (sensorNum == 0) {
		return getNullSensor();
	}
	else if (sensorNum < 10) {
		return getLowSensor();
	}
	else {
		return getHighSensor(sensorNum);
	}
}

int compute_mean(int array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += array[i];
	}
	return sum / size;
}

void sub_call_freeing_non_heap_memory_002_free(int * memory)
{
	freeing_non_heap_memory_002_free(memory);
}

char* memory_leak_001_assign() {
	char* foo = (char*)malloc(10);
	return foo;
}
