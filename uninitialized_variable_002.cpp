/*
Emenda Ltd, 02/05/2018
Uninitialized Variable
*/

struct s {
	int a;
	int b;
};

int z;

s init_struct(int i) {
	if (i == 0) {
		return{ 1,2 };
	}
	else {
		//return{};
	}
}

void uninitialized_variable_002() {
	//struct s x = init_struct(1);
	struct s x;
	x.b = 0;
	z = x.a; //DEFECT
}