#include<stdio.h>
#include<limits.h>
int saturating_add(int x,int y)
{
	int z=x+y;
	int a,b,c;
	a=x>>31;
	b=y>>31;
	c=z>>31;
	int pos_ovf=(~a)&(~b)&c;
	int neg_ovf=(a)&(b)&(~c);
	int non_ovf=(~pos_ovf)&(~neg_ovf);
	return (INT_MIN&neg_ovf) | (INT_MAX&pos_ovf) | (z&non_ovf) ;
}

int main()
{
	printf("please input 2 oeprand:");
	printf("x=");
	int x;
	scanf("%d",&x);
	int y;
	printf("y=");
	scanf("%d",&y);
	int ans;
	ans=saturating_add(x,y);
	printf("%d",ans);
}


