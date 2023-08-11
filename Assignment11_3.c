#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

int Counter = 0;

void * ThreadProc(void *ptr)
{
    int i = 0;
    Counter++;
    printf("Thread executed with counter : %d\n", Counter);
    for(i = 0; i < 0xFFFFFFFF; i++);
    printf("Thread completed with counter : %d\n", Counter);

    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2;
    int Ret1 = 0, Ret2 = 0;

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

    printf("End of main thread\n");

    return 0;
}