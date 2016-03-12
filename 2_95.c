include<stdio.h>
#include<limits.h>
typedef unsigned float_bits;

int float_f2i(float_bits f)
{
	unsigned exp,sign,frac,fvalue,bias;
	int i;
	exp = (f<<1)>>24;
	frac = f&(0x7fffff);
	bias = (1<<7)-1;
	sign = f>>31;
	if (exp!=0) {
		unsigned e = exp -bias;
		fvalue = frac | (1<<23);
		if(sign == 0) {
		if(e==23) return 1;
		if(e<23)	{
			fvalue = fvalue >>(23-e);
			int ans = (int)fvalue; return ans; 
		}
		for (i=1;i<=e-23;i++)
		{
			fvalue=fvalue<<1;
			if(fvalue >((1<<31)-1)) return 0x80000000;
		}
		int ans=(int) fvalue;
		return ans;
		}
		if (sign !=0)	{
		if(e==23) return -1;
		if(e<23) {
			fvalue = fvalue >>(23-e);
			int ans = (int)fvalue; return -ans;
		}
		for (i=1;i<=e-23;i++)	{
			fvalue=fvalue<<1;
			if(fvalue >(1<<31)) return 0x80000000;
			}
		if(fvalue==(1<<31)) return (int) fvalue;
		int ans=-((int)(fvalue));
		return ans;
		}
	}
	else {
		unsigned fue = bias - 1;
		fvalue = frac;
		if (sign ==0)	{
		fvalue=fvalue>>(fue+23);
		int ans = (int) fvalue;
		return ans;
		}
		else	{
		fvalue=fvalue>>(fue+23);
		int ans = (int) fvalue;
		return -ans;
		}
	}
return 0;
}

int main()	{
	printf("please input the bits repretation of float f:");
	float_bits  opr;
	scanf("%x",&opr);
	int end = float_f2i(opr);
	printf("%d",end);
}
			
		
		
			
				
		
		
		
