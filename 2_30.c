#include<stdio.h>
int tadd_ok(int x, int y)	{
	int w=x+y;
	int mask=1<<(sizeof(int)*8-1);
	int a,b,c;
	a=mask&x;
	b=mask&y;
	c=mask&w;
	return !((a==b)&&(c!=a));
}
int main()	{
	printf("please input the 2 operands:");
	int one ,two;
	scanf("%x,%x",&one,&two);
	int i;
	i= tadd_ok(one,two);
	printf("%d",i);
}
