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
	int a = divions_by_zero_001_P();
	divions_by_zero_002_P();
	divions_by_zero_002_N();
	freeing_non_heap_memory_001_P();
	freeing_non_heap_memory_002_P();
	char* foo = nullptr;
	memory_leak_001(foo);
	null_pointer_dereference_001_P();
	null_pointer_dereference_001_P();
	null_pointer_dereference_004_P(0);
	null_pointer_dereference_004_P(3);
	null_pointer_dereference_002_P();
	null_pointer_dereference_002_N();
	null_pointer_dereference_003_P();
	uninitialized_array_001_P();
	uninitialized_array_001_N();
	uninitialized_array_002();
	uninitialized_array_003_P();
	uninitialized_array_003_N();
	uninitialized_heap_001();
	value_unused_001_P();
	value_unused_001_N();
	return 0;
}
