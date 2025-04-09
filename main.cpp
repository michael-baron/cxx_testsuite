#include "main.h"

int main() {

    // buffer_overflow_001.cpp
	buffer_overflow_001_P();
	buffer_overflow_001_N();

    // buffer_overflow_002.cpp
	buffer_overflow_002_P();
	buffer_overflow_002_N();

    // buffer_overflow_003.cpp
	buffer_overflow_003();

    // buffer_overflow_004.cpp
	buffer_overflow_004_P("hello world");
	buffer_overflow_004_N("hello world");

    // buffer_overflow_005.cpp
	buffer_overflow_005_P();
	buffer_overflow_005_N();

    // division_by_zero_001.cpp
	int a = division_by_zero_001_P();

    // division_by_zero_002.cpp
	division_by_zero_002_P();
	division_by_zero_002_N();

    // freeing_non_heap_memory_002.cpp
	freeing_non_heap_memory_002_P();

    // CHECK freeing_unallocated_memory_001.cpp

    // memory_leak_001.cpp
	char* foo = nullptr;
	memory_leak_001(foo);

    // null_pointer_dereference_001.cpp
	null_pointer_dereference_001_P();
	null_pointer_dereference_001_N();

    // null_pointer_dereference_002.cpp
	null_pointer_dereference_002_P();
	null_pointer_dereference_002_N();

    // null_pointer_dereference_003.cpp
	null_pointer_dereference_003_P();

    // null_pointer_dereference_004.cpp
	null_pointer_dereference_004_P(0);
	null_pointer_dereference_004_P(3);

    // uninitialized_array_001.cpp
	uninitialized_array_001_P();
	uninitialized_array_001_N();

    // uninitialized_array_002.cpp
	uninitialized_array_002();

    // uninitialized_array_003.cpp
	uninitialized_array_003_P();
	uninitialized_array_003_N();

    // uninitialized_heap_001.cpp
	uninitialized_heap_001();

    // CHECK uninitialized_variable_001.cpp
    // CHECK uninitialized_variable_002.cpp

    // value_unused_001.cpp
	value_unused_001_P();
	value_unused_001_N();

	return 0;

}
