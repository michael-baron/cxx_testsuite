/*
Emenda Ltd, 02/05/2018
Value Unused
*/

int value1() {
	return 1;
}

int value2() {
	return 2;
}

int value_unused_001_P()
{
	int i;
	i = value1(); //DEFECT
	i = value2();
	return i;
}

int value_unused_001_N()
{
	int i;
	i = value2();
	return i;
}