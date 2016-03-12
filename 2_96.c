#include<stdio.h>
#include<limits.h>
typedef unsigned float_bits;

float_bits float_i2f(int i)
{
	unsigned bias,exp,frac;
	float_bits ans;
	bias = (1<<7)-1;
	if(i==INT_MIN) {
		exp = (31 + bias)<<23; 
		frac = 0 & 0x7fffff;
		ans = (1<<31) | exp | frac;
		return ans;
	}
	if(i==0)	{
		ans = 0;
		return ans;
	}
	if(i==1 || i==-1)	{
		exp = ((1<<7)-1)<<23;
		frac = 0 & 0x7fffff;
		if (i==-1)	{
			ans = (1<<31) | exp | frac;
			return ans;
		}
		if (i==1)	{
			ans = (0) | exp | frac;
			return ans;
		}
	}
	int m;
	if (i>0)	{
	for(m=30;m>=1;m--)	{
		if(((1<<m)&i)!= 0)	{
			if(m>23)	{
			 	frac = (i&((1<<m)-1))>>(m-23);
				exp = (m + bias)<<23;
				ans = 0 | exp | frac;
				return ans;
			}
			if(m<=23)	{
				frac = (i&((1<<m)-1));
				exp = (m + bias)<<23;
				ans = 0 | exp | frac;
				return ans;
			}
		}
	}
	}
	if (i<0)	{
		int w=-i;
		for(m=30;m>=1;m--)	{
			if(((1<<m)&i)!=0)	{
				if(m>23)	{
					frac = (i&((1<<m)-1))>>(m-23);
					exp = (m + bias)<<23;
					ans = (1<<31) | exp | frac;
					return ans;
				}
				if(m<=23)	{
					frac = (i&((1<<m)-1));
					exp = (m + bias)<<23;
					ans = (1<<31) | exp | frac;
					return ans;
				}
			}
		}
	}
	return 0;
}

int main()	{
	printf("please input the operand i:");
	int i;
	scanf("%d",&i);
	float_bits end;
	end = float_i2f(i);
	printf("%x",end);
}
				
			
