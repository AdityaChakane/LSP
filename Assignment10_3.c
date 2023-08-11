#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void * ThreadProc(void *ptr)
{
    printf("Value received from main thread is : %d\n", (int)ptr);
}

int main()
{
    pthread_t TID;
    int Ret = 0;
    int Value = 101;

    Ret = pthread_create(&TID, NULL, ThreadProc, (int *)Value);

    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID, NULL);

    return 0;
}