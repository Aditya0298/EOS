//fork
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc ,char const *argv[]){
pid_t id;
printf("before fork \n");
id=fork();
//printf("after fork \n");
if(0==id){
printf("child pid %d\n",getpid());
printf("child ppid %d\n",getppid());
}
else{
printf("parent pid %d\n",getpid());
printf("parent ppid %d\n",getppid());
}


return 0;
}
         