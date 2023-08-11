#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void * ThreadProc(void *ptr)
{
    printf("INSIDE THREAD\n");
}

int main()
{
    pthread_t TID;
    int Ret = 0;

    Ret = pthread_create(&TID, NULL, ThreadProc, NULL);

    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID : %d\n", TID);

    return 0;
}