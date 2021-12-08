#include<stdio.h>
#include<pthread.h>
int count =10;
pthread_mutex_t mutexCount;
void *inc_thread(void *arg){
    while(1){
        //lock
pthread_mutex_lock(&mutexCount);
count++;
printf("incthread %d\n", count);
pthread_mutex_unlock(&mutexCount);
//unlock
    }
}
void *dec_thread(void *arg){
    while(1){
        //lock 
        pthread_mutex_lock(&mutexCount);
        count--;
        printf("decthread %d\n", count);
        pthread_mutex_unlock(&mutexCount);
        //unlock
    }
}
int main(int argc , char const *argv[]){
    pthread_t incID,decID;
    printf("main thread before\n");
    pthread_mutex_init(&mutexCount,NULL);
    pthread_create(&incID,NULL,inc_thread,NULL);
    pthread_create(&decID,NULL,dec_thread,NULL);
pthread_join(incID,NULL);
pthread_join(decID,NULL);
pthread_mutex_destroy(&mutexCount);
printf("main thread after creating\n");
return 0;

}