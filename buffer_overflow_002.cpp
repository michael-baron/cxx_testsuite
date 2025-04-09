/*
Emenda Ltd, 02/05/2018
Buffer Overflow
*/

void buffer_overflow_002_P()
{
	char a[8];
	for (int i = 0; i < sizeof(a); i++)
    {
		((int*)a)[i] = i; //DEFECT
    }
}

void buffer_overflow_002_N()
{
	char a[8];
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		((int*)a)[i] = i;
	}
}

void new_test(){
    int a[10];
    a[9] = 1;
}
