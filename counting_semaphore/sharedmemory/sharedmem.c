#include<stdio.h>
#include<pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include<unistd.h>
#include<sys/types.h>
int *count;
int num;
int main(){
    int shmd;
    shmd =shm_open("/aditya", O_RDWR |O_CREAT, S_IRUSR | S_IWUSR);
ftruncate(shmd,sizeof(int));
count =(int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shmd, 0);
while(1){
    scanf("%d",&num);
    *count =num;
}
return 0;
}


