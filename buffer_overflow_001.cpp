/*
Emenda Ltd, 02/05/2018
Buffer Overflow
*/

#include <stdio.h>

void buffer_overflow_001_P()
{
    char fixed_buf[10];
    sprintf(fixed_buf, "Very long format string\n"); //DEFECT
}

void buffer_overflow_001_N()
{
    char fixed_buf[10];
    snprintf(fixed_buf, sizeof(fixed_buf), "Very long format string\n");
}

void buffer_overflow_001_P1()
{
    char fixed_buf[10];
    sprintf(fixed_buf, "Very long format string\n"); //DEFECT
}