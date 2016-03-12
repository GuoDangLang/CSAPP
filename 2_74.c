#include<stdio.h>

int tsub_ok(int x,int y)
{
	int ivsy=(~y)+1;
	int z=x+ivsy;
	int mask=1;
	int a=x>>31;
	int b=ivsy>>31;
	int e=z>>31;
	int pos_ovf=(~a)&(~b)&e;
	int neg_ovf=a&b&(~e);
	return ((~pos_ovf)&mask)&((~neg_ovf)&mask);
}

int main()
{
	int x,y;
	printf("please input 2 operands:");
	printf("x=");
	scanf("%d",&x);
	printf("y=");
	scanf("%d",&y);
	int ans=tsub_ok(x,y);
	printf("%d",ans);
}
