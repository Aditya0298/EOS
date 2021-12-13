#include<stdio.h>
#include<pthread.h>

int count = 0;  //global variable

void * incThread(void *data)  //Thread T1
{
    while (1)
    {
        count++;
        printf("Inc Count: %d\n", count);
    }
}
void * decThread(void *data)   //Thread T2
{
    while (1)
    {
        count--;
        printf("Dec Count: %d\n", count);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t incId, decId;

    pthread_create(&incId, NULL, incThread, NULL);
    pthread_create(&decId, NULL, decThread, NULL);

    pthread_join(incId, NULL);
    pthread_join(decId, NULL);
    return 0;
}