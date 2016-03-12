#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,int len) {
	int i;
	for(i=0;i<len;i++)
		printf("%.2x",start[i]);
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x,sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x,sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x,sizeof(void));
}

void show_short(short x)	{
	show_bytes((byte_pointer) &x,sizeof(short));
}

void show_long(long x)	{
show_bytes((byte_pointer) &x,sizeof(long));
}

void show_double(double x)	{
show_bytes((byte_pointer) &x,sizeof(double));
}

int main()	{
	int x=12345;
	float y=x;
	short m=x;
	double n=y;	
	void *z=NULL;
	show_int(x);
	show_float(y);
	show_pointer(z);
	show_short(m);
	show_double(n);
}	
