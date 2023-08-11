#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void * ThreadProc1(void *ptr)
{
    int fd = 0;
    char Buffer[1024];
    int iRet = 0;
    int i = 0;
    int iCnt = 0;

    fd = open("demo.txt", O_RDONLY);

    while((iRet = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of capital characters are : %d\n", iCnt);

    close(fd);

    pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
    int fd = 0;
    char Buffer[1024];
    int iRet = 0;
    int i = 0;
    int iCnt = 0;

    fd = open("demo.txt", O_RDONLY);

    while((iRet = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of small characters are : %d\n", iCnt);

    close(fd);

    pthread_exit(NULL);
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

    printf("End of main thread\n");

    return 0;
}