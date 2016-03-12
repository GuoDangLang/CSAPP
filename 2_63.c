#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
unsigned srl(unsigned x, int k)	{
	unsigned xsra = (int) x >> k;
	int shift = 8*sizeof(int)-k;
	int v=~((-1)<<shift);
	unsigned destination=xsra&v;
	return destination;
}

unsigned sra(int x, int k)	{
	int xsrl = (unsigned) x >>k;
	int w=(sizeof(int))<<3;
	int z=1<<(w-k-1);
	int mask = z-1;
	int right=mask & xsrl;
	int left=~mask &((~(z&xsrl))+z);
	return left | right;
}

int main()	{
	printf("please input an unsigned num to do logical shift:");
	unsigned lgc;
	scanf("%x",&lgc);
	printf("please input an int num to do arithmetic shift:");
	int atm;
	scanf("%x",&atm);
	printf("Please input the k:");
	int k;
	scanf("%d",&k);
	printf("srl:%x,sra:%x",srl(lgc,k),sra(atm,k));
}



	
	
