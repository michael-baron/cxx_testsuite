/*
Emenda Ltd, 02/05/2018
Uninitialized Array
*/

#include <stdio.h>
#include <string.h>

void uninitialized_array_001_P()
{
	char str[20];
	strcat(str, "world");
	printf("%s", str);
}

void uninitialized_array_001_N()
{
	char str[20] = "hello ";
	strcat(str, "world");
	printf("%s", str);
}