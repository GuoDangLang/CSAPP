#include<stdio.h>
#include<limits.h>

typedef unsigned float_bits;

float_bits float_negate (float_bits f)
{
	unsigned sign = f >>31;
	if ((f<<1)==(UINT_MAX-1)) return f;
	else  return (1<<31)^f;
}

int main()
{

	
