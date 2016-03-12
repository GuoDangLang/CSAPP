#include<stdio.h>
int odd_ones(unsigned x)	{
	unsigned a,b,c,d,e,f,g,h;
	unsigned i,q,k,l,m,n,o,p;
	a=(x&0xf);
	b=((x>>4)&0xf);
	c=((x>>8)&0xf);
	d=((x>>12)&0xf);
	e=((x>>16)&0xf);
	f=((x>>20)&0xf);
	g=((x>>24)&0xf);
	h=((x>>28)&0xf);

	i=a&1+(a>>1)&1+(a>>2)&1+(a>>3)&1;
	q=b&1+(b>>1)&1+(b>>2)&1+(b>>3)&1;
	k=c&1+(c>>1)&1+(c>>2)&1+(c>>3)&1;
	l=d&1+(d>>1)&1+(d>>2)&1+(d>>3)&1;
	m=e&1+(e>>1)&1+(e>>2)&1+(e>>3)&1;
	n=f&1+(f>>1)&1+(f>>2)&1+(f>>3)&1;
	o=g&1+(g>>1)&1+(g>>2)&1+(g>>3)&1;
	p=h&1+(h>>1)&1+(h>>2)&1+(h>>3)&1;
	
	unsigned sum;
	sum=i+q+k+l+m+n+o+p;
	return sum&1;
}
int main()	{
	printf("please input the num you want to operate:");
	unsigned x;
	scanf("%x",&x);
	int w;
	w=odd_ones(x);
	printf("%d\n",w);
}
