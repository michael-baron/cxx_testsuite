/*
Emenda Ltd, 02/05/2018
Division By Zero
*/

int divions_by_zero_002_P() {
	int sum = 0;
	for (int i = -10; i < 10; ++i) {
		sum += 3628800 / i; //DEFECT
	}
	return sum;
}

int divions_by_zero_002_N() {
	int sum = 0;
	for (int i = -10; i < 10; ++i) {
		if (i != 0) {
			sum += 3628800 / i;
		}
	}
	return sum;
}