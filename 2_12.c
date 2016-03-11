#include<stdio.h>
void	A(int x)
{
	printf("%.16x\n",x&0xFF);
}
void	B(int x)
{
	printf("%.16x\n",x^(~0xFF));
}
void	C(int x)
{
	printf("%.16x\n",x|0xFF);
}

int	main()
{
	int w,z;
	printf("hex for 1,decimal for 2:");
	scanf("%x",&z);
	switch(z)
	{
		case 1: printf("please input a the hex to operate:");
			scanf("%x",&w);
			break;
		case 2: printf("please input a the decimal to operate:");
			scanf("%d",&w);
			break;
	}
	A(w);
	B(w);
	C(w);
}
	
	



