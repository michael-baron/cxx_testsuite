/*
Emenda Ltd, 02/05/2018
Uninitialized Heap
*/

#include<stdlib.h>

typedef struct {
	int x;
} S1;

typedef struct {
	S1* ptr;
} S2;

void foo(S1* ptr) {
	int k = ptr ? ptr->x : -1;
}

int uninitialized_heap_001() {
	S2* ps = (S2*)malloc(sizeof(S2));
	if (ps != NULL) {
		foo(ps->ptr); //DEFECT
		free(ps);
	}
	return 0;
}