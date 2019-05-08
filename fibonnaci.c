#include<stdio.h>
#include<time.h>
 
int fib(int);
int fork(void);
int sleep(unsigned);
 
int main()
{
int begin = time(NULL), i;
 
if (fork() == 0)  /*child*/
for(i=0; i<30; i++)
printf("fib(%2d)=%d\n", i, fib(i));
else    /*parent*/
for(i=0; i<30; i++)
{
sleep(2);
printf("Elapsed time = %d\n", time(NULL)-begin);
}
 
 
return 0;
}
 
int fib(int n)
{
if (n<=1)
return n;
else
return (fib(n-1) +fib(n-2));
}
