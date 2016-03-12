#include<stdio.h>

int fits_bits (int x, int n)	{
	return x==((~(-1<<(n)))&x);
}

int main()	{
	printf("please input the num you want to tell:");
	int x;
	scanf("%x",&x);
	printf("please input n:");
	int n;
	scanf("%d",&n);
	int b=fits_bits (x, n);
	printf("%d",b);
}
