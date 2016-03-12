#include<stdio.h>

int mul3div4(int x)
{
	int add=(x<<1)+x;
	int ans=(add+((add>>31)&((1<<2)-1)))>>2;
	return ans;
}

int main()	
{
	printf("please input the value of x:");
	int x;
	printf("x=");
	scanf("%d",&x);
	int ans=mul3div4(x);
	printf("%d",ans);
}
	
	
	
