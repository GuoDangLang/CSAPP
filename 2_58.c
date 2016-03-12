#include<stdio.h>
typedef char *type_pointer;

int show_first(type_pointer x)
{
	 return x[0];	
}

int main()	{
	int m=1,w;
	w=show_first((type_pointer) &m);
	if (w==1) printf("little endians");
	else printf("Big endians");
}

	
	
