#include<stdio.h>
int main()	{
	int x,y;
	printf("please input 2 hexadecimal to operate:");
	scanf("%x,%x",&x,&y);
	int m,n;
	m=x&(0xff);
	n=y&(~0xff);
	int z;
	z=m+n;
	printf("%x",z);
}
