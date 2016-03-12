#include<stdio.h>
unsigned rotate_left (unsigned x, int n)	{
	unsigned w = sizeof(int)*8;
	unsigned shift = w-1-n;
	unsigned i=(-2)<<shift;
	unsigned p=i&x;
	unsigned q=(p>>1)>>shift;
	unsigned ans=q+(x<<n);
	return ans;
}

int main()	{
	printf("please input the num you want to rotate:");
	unsigned num,n;
	scanf("%x",&num);
	printf("how many bits you want to rotate:");
	scanf("%u",&n);
	unsigned destination = rotate_left (num, n);
	printf("%x",destination);
}
	
	
