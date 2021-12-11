#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_barrier_t init_barrier;
void *i2c_thread(void *data){
printf("i2c started");
pthread_barrier_wait(&init_barrier);
printf("12c init completed\n");
}
void *eth_thread(void *data){
printf("eth started");
pthread_barrier_wait(&init_barrier);
printf("eth init completed\n");
}
void *uart_thread(void *data){
printf("uart started");
pthread_barrier_wait(&init_barrier);
printf("uart init completed\n");
}
void *usart_thread(void *data){
printf("usart started");
pthread_barrier_wait(&init_barrier);
printf("usart init completed\n");
}
int main(int argc , char const *argv[]){
    pthread_t i2c,eth,uart,usart;
    pthread_barrier_init(&init_barrier,NULL,4);
    pthread_create(&i2c,NULL,i2c_thread,NULL);
    pthread_create(&eth,NULL,eth_thread,NULL);
    pthread_create(&uart,NULL,uart_thread,NULL);
    pthread_create(&usart,NULL,usart_thread,NULL);
    pthread_join(i2c,NULL);
    pthread_join(eth,NULL);
    pthread_join(uart,NULL);
    pthread_join(usart,NULL);
    return 0;
    
}