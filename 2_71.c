#include<stdio.h>
typedef unsigned packed_t;

int xbyte(packed_t word,int bytenum)
{
	int ret=(word<<((3-bytenum)<<3));
	return (ret>>24);
}

int main()
{
	printf("please input the operand:");
	unsigned x;
	scanf("%x",&x);
	int z;
	printf("which byte you want to extract:");
	int bn;
	scanf("%d",&bn);
	z=xbyte(x,bn);
	printf("%x",z);
}
