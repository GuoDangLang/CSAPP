#include<stdio.h>
int leftmost_one(unsigned x)	{
	x |=(x>>1);
	x |=(x>>2);
	x |=(x>>4);
	x |=(x>>8);
	x |=(x>>16);
	return x^(x>>1);
}

int main()	{
	int i;
	unsigned u;
	printf("please input the num you want to get the mask of:");
	scanf("%x",&u);
	i=leftmost_one(u);
	printf("%x",i);
}

	
		
