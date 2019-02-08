/*
Emenda Ltd, 02/05/2018
Null Pointer Dereference
*/

#include "functions_002.h"

int null_pointer_dereference_001_global;

void null_pointer_dereference_001_P() {
	int *p = xmalloc();
	*p = 1; //DEFECT
}

void null_pointer_dereference_001_N() {
	int *p = xmalloc();
	if (p) {
		*p = 1;
	}
}