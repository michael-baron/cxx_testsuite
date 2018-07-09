/*
Emenda Ltd, 02/05/2018
Freeing Non Heap Memory
*/

#include "functions_001.h"
#include "functions_002.h"

void freeing_non_heap_memory_002_P()
{
	int localArray[2] = { 11, 22 };
	sub_call_freeing_non_heap_memory_002_free(localArray); //DEFECT
	freeing_non_heap_memory_002_free(localArray); //DEFECT
}