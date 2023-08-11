#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void * ThreadProc2(void *ptr)
{
    int i = 0;

    for(i = 500; i > 0; i--)
    {
        printf("%d\n", i);
    }
}

void * ThreadProc1(void *ptr)
{
    int i = 0;

    for(i = 1; i <= 500; i++)
    {
        printf("%d\n", i);
    }
}

int main()
{
    pthread_t TID1, TID2;
    int Ret1 = 0, Ret2 = 0;

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

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    return 0;
}