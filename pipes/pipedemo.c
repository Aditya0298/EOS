#include<stdio.h>
 #include <sys/types.h>
       #include <unistd.h>

int main(int argc , char const *argv[])
{
    pid_t id;
    unsigned char buff [16];
    int fd[2];
    pipe (fd);
    id=fork();
    if(0==id){
        printf("child is reading\n");
        read(fd[0],buff,16);
        printf("child reading %s\n",buff);
    }
    else{
        printf("writing\n");
        write(fd[1],"aditya\n",7);
        printf("writing done\n");
    }
 return 0;
}