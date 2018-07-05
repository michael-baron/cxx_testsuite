/*
Emenda Ltd, 02/05/2018
Null Pointer Dereference
*/

int null_pointer_dereference_001_global;

int *xmalloc() {
	if (null_pointer_dereference_001_global) {
		return &null_pointer_dereference_001_global;
	}
	return 0;
}

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