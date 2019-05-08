#include <stdio.h>

int main(){
	int x, y, z;

	int *p, *q, *r;


	p=&x;

	q=&y;

	r=&z;


	*p=6;

	y=20,

	*r=10;


	*p=*q+*p;

	q=r;

	p=&y;


	*p=*q+y;




	printf("x,y,z,p,q,r is %d,%d,%d,%d,%d,%d \n",x,y,z,*p,*q,*r);
}