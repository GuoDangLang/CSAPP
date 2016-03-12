#include<stdio.h>

void bobble_i(int *data,int count)	{
	int last,i;
	for(last = count-1;last >0;last--)	{
		for( i = 0;i < last; i++)	{
			if(*(data+i+1)<*(data+i))	{
			int t = *(data+i+1);
			*(data+i+1) = *(data+i);
			*(data+i) = t;
			}
		}
	}
}
