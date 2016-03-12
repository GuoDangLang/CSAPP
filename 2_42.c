#include<stdio.h>
int div16(int x) {
	int w=((x+(1<<4)-1))>>4;
	unsigned mask;
	mask=1<<((sizeof(int)*8)-1);
	return w-((!(mask&x))&&(x&(0xf)));
}

int main()	{
	int x;
	printf("please input the operand x:");
	scanf("%d",&x);
	int ans;
	ans =div16(x);
	printf("%d",ans);
}
