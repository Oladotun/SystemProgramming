#include<stdio.h>
int fork(void);
int main()
{
if (fork() == 0)  /*child*/
 
printf("Hello\n");
else    /*parent*/
 
 
printf("Goodbye \n");
 
 
 
return 0;
}
