#include "main.h"

int main() {
	buffer_overflow_001_P();
	buffer_overflow_001_N();
	buffer_overflow_002_P();
	buffer_overflow_002_N();
	buffer_overflow_003();
	buffer_overflow_004_P("hello world");
	buffer_overflow_004_N("hello world");
	buffer_overflow_005_P();
	buffer_overflow_005_N();
	null_pointer_dereference_004_P(0);
	null_pointer_dereference_004_P(3);
	int a = divions_by_zero_001_P();
	divions_by_zero_002_P();
	divions_by_zero_002_N();
	freeing_non_heap_memory_002_P();
	char* foo = nullptr;
	memory_leak_001(foo);
	return 0;
}
