#include<stdio.h>
#include<time.h>
 
int fork(void);
int sleep(unsigned);
 
int main()
{
        int begin = time(NULL), i;
 
        if (fork() == 0)    /*child*/
                for(i=0; i<5; i++)
                printf("Hello\n");
        else                             /*parent*/
                for(i=0; i<5; i++)
                {
                        sleep(2);
                        printf("Elapsed time = %d\n", time(NULL)-begin);
                }
 
 
        return 0;
}        
