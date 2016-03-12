#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
typedef char *byte_pointer;
void replace_byte (unsigned x, int i, unsigned b)	{
	printf("%x",(x&(~(0xff<<(32-8*i))))+(b<<(32-8*i)));
}
	
int main()	{
	unsigned o,p,q;
	printf("please the value x you want to replace:");
	scanf("%x",&o);
	printf("please the position of replaced byte:");
	scanf("%u",&p);
	if(p>sizeof(unsigned)) exit(ERROR);
	printf("please input the num for replacement:");
	scanf("%x",&q);
	replace_byte(o,p,q);
}

	
