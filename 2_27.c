#include<stdio.h>
int uadd_ok(unsigned x, unsigned y)
{
	if(x+y<x) return 1;
	else return 0;
}

int main()
{
	unsigned int m,n,i;
	printf("please input two unsigned int for addition:");
	scanf("%u,%u",&m,&n);
	i=uadd_ok(m,n);
	printf("%d\n",i);
}
		
