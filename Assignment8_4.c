#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int Ret1 = 0, Ret2 = 0;
    int cpid1 = 0, cpid2 = 0;
    int Exit_Status1 = 0, Exit_Status2 = 0;

    printf("Parent is running with PID : %d\n", getpid());

    Ret1 = fork();

    if(Ret1 == 0)
    {
        printf("Child 1 is running with PID : %d\n", getpid());
        printf("Child 1 says : PID of parent is : %d\n", getppid());
        exit(0);
    }
    else
    {
        //printf("Parent is running with PID : %d\n", getpid());
        cpid1 = wait(&Exit_Status1);
        printf("Child process terminated having PID : %d\n", cpid1);
    }
    
    
    Ret2 = fork();

    if(Ret2 == 0)
    {
        printf("Child 2 is running with PID : %d\n", getpid());
        printf("Child 2 says : PID of parent is : %d\n", getppid());
        exit(0);
    }
    else
    {
        //printf("Parent is running with PID : %d\n", getpid());
        cpid2 = wait(&Exit_Status2);
        printf("Child process terminated having PID : %d\n", cpid2);
    }

    return 0;
}