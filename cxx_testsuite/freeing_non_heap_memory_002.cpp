/*
Emenda Ltd, 02/05/2018
Freeing Non Heap Memory
*/

void freeing_non_heap_memory_002_free(int * memory)
{
	delete[] memory;
}

void freeing_non_heap_memory_002_P()
{
	int localArray[2] = { 11, 22 };
	freeing_non_heap_memory_002_free(localArray); //DEFECT
}