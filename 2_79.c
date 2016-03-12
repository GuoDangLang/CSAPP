#include<stdio.h>
#include<limits.h>
int threefourths (int x)
{
	int sign = x&INT_MIN;
	int base = (x>>1)+(x>>2);
	int tail = ((x&1)<<1)+(x&3);
	int bias = (tail>>2)+(sign&&(tail&3));
	return base + bias;
}

int main()
{
	printf("please input the operand x:");
	int x;
	scanf("%d",&x);	
	int ans = threefourths (x);
	printf("the answer is:%d",ans);
}
