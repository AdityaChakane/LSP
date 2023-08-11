#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

int Counter = 0;

pthread_mutex_t lock;

void * ThreadProc(void *ptr)
{
    pthread_mutex_lock(&lock);

    int i = 0;
    Counter++;
    printf("Thread executed with counter : %d\n", Counter);
    for(i = 0; i < 0xFFFFFFFF; i++);
    printf("Thread completed with counter : %d\n", Counter);

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2;
    int Ret1 = 0, Ret2 = 0;

    pthread_mutex_init(&lock, NULL);

    Ret1 = pthread_create(&TID1, NULL, ThreadProc, NULL);

    if(Ret1 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    Ret2 = pthread_create(&TID2, NULL, ThreadProc, NULL);

    if(Ret2 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }


    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    pthread_mutex_destroy(&lock);

    printf("End of main thread\n");

    return 0;
}