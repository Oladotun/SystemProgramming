#include <stdio.h>

void increment(int *a, int *b);

int main()
{
	int x,y;
	x=5;
	y=7;

	printf("x is %d and y is %d before increment \n",x,y );

	increment(&x,&y);

	printf("x is %d and y is %d \n",x,y );
}

void increment(int *a, int *b)
{
	*a = *a + 1;
	*b = *b + 1;

	printf("a is %d and b is %d\n",*a,*b );
}