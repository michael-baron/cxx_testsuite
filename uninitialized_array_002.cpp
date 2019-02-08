/*
Emenda Ltd, 02/05/2018
Uninitialized Array
*/

#include <stdio.h>
#include <string.h>

void uninitialized_array_002_P(char * str)
{
	strcat(str, "world");
	printf("%s", str);
}

void uninitialized_array_002_N(char * str)
{
	strcat(str, "world");
	printf("%s", str);
}

void uninitialized_array_002() {
	char str[20];
	uninitialized_array_002_P(str); //DEFECT
	for (int i = 0; i < 10; i++) {
		str[i] = 'a';
	}
	uninitialized_array_002_N(str);
}