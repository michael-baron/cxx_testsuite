/*
Emenda Ltd, 02/05/2018
Uninitialized Variable
*/

class C {
	int i;
	int j;
public:
	C() {
		this->j = 0;
	} //DEFECT
};