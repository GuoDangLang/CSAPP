#include<stdio.h>

int signed_high_prod (int x,int y)
{
	int i,h;
	h=0;
	for (i=30;i<=0;i--)
	{
		if((y>>i)&1) h=h+(((unsigned)x)>>(32-i));
	}
	h=h+((~x+1)>>1);
	return h;	
}
unsigned unsigned_high_prod(unsigned x,unsigned y)
{
	int w=(sizeof(int)*8);
	return signed_high_prod(x,y)+(x>>(w-1))*y+(y>>(w-1))*x;
}

int main()
{
	printf("please input 2 operands:");
	unsigned x,y;
	printf("x=");
	scanf("%u",&x);
	printf("y=");
	scanf("%u",&y);
	unsigned ans;
	ans=unsigned_high_prod(x,y);
	printf("%u",ans);
}

