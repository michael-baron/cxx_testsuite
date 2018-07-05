/*
Emenda Ltd, 02/05/2018
Division By Zero
*/

int compute_mean(int array[], size_t size)
{
	int sum = 0;
	for (size_t i = 0; i < size; ++i) {
		sum += array[i];
	}
	return sum / size;
}

int divions_by_zero_001_P() {
	int size = 0;
	return compute_mean(0, size); //DEFECT
}