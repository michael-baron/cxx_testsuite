/*
Emenda Ltd, 02/05/2018
Division By Zero
*/

#include "functions_001.h"

int division_by_zero_001_P() {
	int size = 0;
	return compute_mean(0, size); //DEFECT
}
