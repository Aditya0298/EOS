#include<stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
  #include <unistd.h>
int main(int argc, char const *argv[]){
    int fd;
    fd=open("desdfile",O_WRONLY);
    write(fd,"aditya\n",7);
    close (fd);
    return 0;
}