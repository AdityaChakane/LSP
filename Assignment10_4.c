#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void * ThreadProc(void *ptr)
{
    int val = (int)ptr;

    printf("Value received from main thread is : %d\n", val);

    val = val + 10;

    pthread_exit(val);
}

int main()
{
    pthread_t TID;
    int Ret = 0;
    int Value = 101;
    int retValue = 0;

    Ret = pthread_create(&TID, NULL, ThreadProc, (int *)Value);

    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID, &retValue);

    printf("Return value from child thread is : %d\n", retValue);

    return 0;
}