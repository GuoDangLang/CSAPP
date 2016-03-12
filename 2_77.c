#include<stdio.h>

int divide_power2(int x, int k)
{
	int w,weight;
	w=(sizeof(int)<<3);
	weight=x>>(w-1);
	return (x+((1<<k)-1)&(weight))>>k;
}

int main()
{
	int x,y,ans;
	printf("please input 2 operands:");
	printf("x=");
	scanf("%d",&x);
	printf("y=");
	scanf("%d",&y);
	ans=divide_power2(x,y);
	printf("%d",ans);
}
