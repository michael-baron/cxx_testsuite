/*
Emenda Ltd, 02/05/2018
Uninitialized Variable
*/

struct s {
	int a;
	int b;
};

int z;

void uninitialized_variable_002() {
	struct s x;
	x.b = 0;
	z = x.a; //DEFECT
}