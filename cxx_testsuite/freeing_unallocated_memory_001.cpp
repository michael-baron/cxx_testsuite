/*
Emenda Ltd, 02/05/2018
Freeing Unallocated Memory
*/

#include <stdlib.h>
/*
typedef struct list {
	char * next;
} list;
typedef struct z {
	list l;
} z;

void freeing_unallocated_memory_001_P()
{
	z * x = malloc(sizeof(z));
	if (!x) {
		return;
	}
	x->l.next = "hello world";
	free(x->l.next);
	free(x);
}
*/
typedef struct list {
	char * next;
} list;
typedef struct z {
	list l;
} z;

void a6() { // 8923
	z * x = malloc(sizeof(z));
	if (!x) return;
	x->l.next = 1;
	free(x->l.next);
}