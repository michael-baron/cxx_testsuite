/*
Emenda Ltd, 02/05/2018
Uninitialized Array
*/

void uninitialized_array_003_P()
{
	int arr[5];
	int n;
	n = arr[((sizeof arr) / (sizeof *arr)) - 1]; //DEFECT
}

void uninitialized_array_003_N()
{
	int arr[5] = { 0,0,0,0,0 };
	int n;
	n = arr[((sizeof arr) / (sizeof *arr)) - 1];
}