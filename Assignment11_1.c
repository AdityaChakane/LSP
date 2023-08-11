#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void * ThreadProc1(void *ptr)
{
    printf("Inside thread 1\n");
}

void * ThreadProc2(void *ptr)
{
    printf("Inside thread 2\n");
}

void * ThreadProc3(void *ptr)
{
    printf("Inside thread 3\n");
}

void * ThreadProc4(void *ptr)
{
    printf("Inside thread 4\n");
}

int main()
{
    pthread_t TID1, TID2, TID3, TID4;
    int Ret1 = 0, Ret2 = 0, Ret3 = 0, Ret4 = 0;

    Ret1 = pthread_create(&TID1, NULL, ThreadProc1, NULL);

    if(Ret1 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    Ret2 = pthread_create(&TID2, NULL, ThreadProc2, NULL);

    if(Ret2 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    Ret3 = pthread_create(&TID3, NULL, ThreadProc3, NULL);

    if(Ret3 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    Ret4 = pthread_create(&TID4, NULL, ThreadProc4, NULL);

    if(Ret4 != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);
    pthread_join(TID3, NULL);
    pthread_join(TID4, NULL);

    printf("End of main thread\n");

    return 0;
}