#include<stdio.h>
 #include <sys/types.h>
       #include <unistd.h>
int main(int argc,char const *argv[])
{
    printf("id: %d\n",getpid());
    printf("parent id: %d\n",getppid());
    return 0;
    
    

}