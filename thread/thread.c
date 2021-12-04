#include<stdio.h>
#include<pthread.h>
void *greet_thread(void *arg)
{
    printf("%s thread\n", arg);
}

int main(int argc , char const *argv[])
{
    pthread_t helloID, byeID;
    printf("main thread: before calling hello thread\n");
 pthread_create(&helloID,NULL,greet_thread,"Hello");
  pthread_create(&byeID,NULL,greet_thread,"Bye");
  pthread_join(helloID,NULL);
pthread_join(byeID,NULL);
printf("main   :after creating hello\n");
return 0;
}