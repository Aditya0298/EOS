#include<stdio.h>
#include<pthread.h>
int count =10;
pthread_mutex_t mutexCount;
pthread_mutexattr_t mutexCountAttr;
void square(){
    pthread_mutex_lock(&mutexCount);
    count =count *count;
    pthread_mutex_unlock(&mutexCount);
}
void inc_thread(void *arg){
while(1){
    //lock
    //printf("inc while loop after locking\n");
    pthread_mutex_lock(&mutexCount);
    count++;
    square();
    printf("inc thread %d\n", count);
    pthread_mutex_unlock(&mutexCount);
    //unlock
     //printf("inc while loop after unlocking\n");
}
}
void dec_thread(void *arg){
    while(1){
        //printf("dec while loop\n");
        //lock 
        // printf("dec while after lock loop\n");
        pthread_mutex_lock(&mutexCount);
        count--;
        printf("dec thread is %d\n:",count);
        //unlock
         //printf("dec while after unlock loop\n");
        pthread_mutex_unlock(&mutexCount);
    }
}
int main(int argc , char const *argv[]){
    pthread_t incID, decID;

printf("main thread beforr creating\n");
//setting attributes
pthread_mutexattr_settype(&mutexCountAttr , PTHREAD_MUTEX_RECURSIVE);
//init attributes
pthread_mutex_init(&mutexCount, &mutexCountAttr );
pthread_create(&incID,NULL,inc_thread,NULL);
pthread_create(&decID,NULL,dec_thread,NULL);
pthread_join(incID,NULL);
pthread_join(decID,NULL);
//destroy mutex
pthread_mutex_destroy(&mutexCount);
printf("main thread after creating\n");
return 0;
}
