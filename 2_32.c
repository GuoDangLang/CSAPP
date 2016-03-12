#include<stdio.h>
int tsub_ok (int x, int y)	{
	int w;
	w=x-y;
	int mask=1<<(8*sizeof(int)-1);
	int u,v,e;
	u=x&mask;
	v=y&mask;
	e=w&mask;
	return !((u!=v)&&(u!=e));
}

int main()	{
	printf("please input 2 operands:");
	int one,two;
	scanf("%x,%x",&one,&two);
	int ans;
	ans=tsub_ok (one,two);
	printf("%d",ans);
}
