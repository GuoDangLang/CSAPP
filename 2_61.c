#include<stdio.h>
int A(int x)	{
	int d;
	d=!(x^(-1));
	return d;
}

int B(int x)	{
	int d;
	d=!(x^(0));
	return d;
}

int C(int x)	{
	int d;
	d=!(0xff^(x&(0xff)));
	return d;
}

int D(int x)	{
	int d;
	int shiftlen=(sizeof(int)-1)<<3;
	int w=(x>>shiftlen)&0xff;
	d=!(w^0);
	return d;
}

int main()	{
	printf("please input a num you want to evaluate:");
	int t;
	scanf("%x",&t);
	int a=A(t);
	int b=B(t);
	int c=C(t);
	int d=D(t);
	printf("%d\n%d\n%d\n%d\n",a,b,c,d);
}
	
