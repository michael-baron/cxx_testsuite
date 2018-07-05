/*
Emenda Ltd, 02/05/2018
Buffer Overflow
*/

void buffer_overflow_005_P()
{
	int arr[5] = {0,0,0,0,0};
	int n;
	n = arr[sizeof(arr) - 1]; //DEFECT
}

void buffer_overflow_005_N()
{
	int arr[5] = { 0,0,0,0,0 };
	int n;
	n = arr[((sizeof arr) / (sizeof *arr)) - 1];
}