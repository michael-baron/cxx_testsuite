/*
Emenda Ltd, 02/05/2018
Null Pointer Dereference
*/

int null_pointer_dereference_002_global;

void null_pointer_dereference_002_P() {
	int *p;
	if (null_pointer_dereference_002_global) {
		p = &null_pointer_dereference_002_global;
	}
	else {
		p = 0;
	}
	if (p) {
		// Do Something
	}
	p[0] = 0;
}

void null_pointer_dereference_002_N() {
	int *p;
	if (null_pointer_dereference_002_global) {
		p = &null_pointer_dereference_002_global;
	}
	else {
		p = 0;
	}
	if (p) {
		// Do Something
		p[0] = 0;
	}
}