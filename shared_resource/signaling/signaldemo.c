#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int a,b;
int sum;
sem_t s1,s2;
void *input_thread(void *arg){
    while(1){
sem_post(&s1);
//printf("print two no\n");
scanf("%d\n",&a);
scanf("%d\n",&b);
sem_wait(&s2);
    }
}
void *proc_thread(void *arg){
    while(1){
        //lock
    sem_post(&s2);
   // printf("result is\n");
    sum= a + b;
    printf("sum:%d\n",a+b);
    sem_wait(&s1);
    //unlock
    }
}
int main(int argc , char const *argv[]){
    pthread_t inputTid, procTid;
    sem_init(&s1, 0 , 1);
    sem_init(&s2, 0 ,0);
    pthread_create(&inputTid, NULL,input_thread,NULL);
    pthread_create(&procTid,NULL,proc_thread,NULL);
    pthread_join(inputTid,NULL);
    pthread_join(procTid,NULL);
    //sem_destroy(&s1);
    //sem_destroy(&s2);
    return 0;
    }