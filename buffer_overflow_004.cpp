/*
Emenda Ltd, 02/05/2018
Buffer Overflow
*/

#include <string.h>

void buffer_overflow_004_P(char * src)
{
    char buf[8];
    char tgt[1024];
    strncpy(buf, src, 3);
    strcpy(tgt, buf); //DEFECT
}

void buffer_overflow_004_N(char * src)
{
	char buf[8];
	char tgt[1024];
	strncpy(buf, src, 3);
	// ensure null termination
	buf[3] = '\0';
	strcpy(tgt, buf);
}