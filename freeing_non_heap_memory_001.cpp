/*
Emenda Ltd, 02/05/2018
Freeing Non Heap Memory
*/

void freeing_non_heap_memory_001_P()
{
	int localArray[2] = { 11, 22 };
	delete[] localArray; //DEFECT
}