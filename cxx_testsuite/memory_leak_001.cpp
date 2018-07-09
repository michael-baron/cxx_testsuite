/*
Emenda Ltd, 02/05/2018
Memory Leak
*/

#include <stdlib.h>
#include "functions_001.h"

void memory_leak_001_free(char* foo) {
	free(foo);
}

void memory_leak_001(char* foo) {
	for (int i = 0; i < 10; i++) {
		foo = memory_leak_001_assign(); //DEFECT
	}
	memory_leak_001_free(foo);
}