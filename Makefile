CXX=g++
RM=rm -f

CPPFLAGS=-fpermissive -w -std=gnu++0x

SRCS= buffer_overflow_001.cpp buffer_overflow_002.cpp buffer_overflow_003.cpp buffer_overflow_004.cpp buffer_overflow_005.cpp division_by_zero_001.cpp division_by_zero_002.cpp freeing_non_heap_memory_001.cpp freeing_non_heap_memory_002.cpp freeing_unallocated_memory_001.cpp functions_001.cpp functions_002.cpp main.cpp memory_leak_001.cpp null_pointer_dereference_001.cpp null_pointer_dereference_002.cpp null_pointer_dereference_003.cpp null_pointer_dereference_004.cpp uninitialized_array_001.cpp uninitialized_array_002.cpp uninitialized_array_003.cpp uninitialized_heap_001.cpp uninitialized_variable_001.cpp uninitialized_variable_002.cpp value_unused_001.cpp

OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS) $(LDLIBS)

clean:
	$(RM) $(OBJS) main
