/*
Emenda Ltd, 02/05/2018
Buffer Overflow
*/

void buffer_overflow_003_P(int x)
{
	int local_array[7];
	local_array[x] = 0;
}

void buffer_overflow_003_N(int x)
{
	int local_array[7];
	if (x >= 0 && x < 7){
		local_array[x] = 0;
	}
}

void buffer_overflow_003() {
	buffer_overflow_003_P(15); //DEFECT
	buffer_overflow_003_N(15);
}