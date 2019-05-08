#include<stdio.h>
int main()
{
        int fork (), value;
        value = fork();
        value = fork();
        printf("In main: value = %d\n", value);
 
 
        return 0;
}
