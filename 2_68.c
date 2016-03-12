#include<stdio.h>
int lower_one_mask(int n)	{
	int i=2<<(n-1);
	i=i-1;
	return i;
}

int main()	{
	int n;
	printf("please input the n value:");
	scanf("%d",&n);
	int z=lower_one_mask(n);
	printf("%x",z);
}
