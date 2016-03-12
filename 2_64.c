#include<stdio.h>
int any_odd_one(unsigned x)	{
	return x==0xcccccccc;
}

int main()	{
	printf("please input the num:");
	unsigned x;
	scanf("%u",&x);
	printf("x=%x\n",x);
	int z;
	z=any_odd_one(x);
	printf("%d",z);
}

