#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int Ret1 = 0, Ret2 = 0, Ret3 = 0;
    int cpid1 = 0, cpid2 = 0, cpid3 = 0;
    int Exit_Status = 0;

    printf("Parent is running with PID : %d\n", getpid());

    Ret1 = fork();

    if(Ret1 == 0)
    {
        
        printf("Child 1 is running with PID : %d\n", getpid());
        printf("Child 1 says : PID of parent is : %d\n", getppid());
    }
    
    
    Ret2 = fork();

    if(Ret2 == 0)
    {
        
        printf("Child 2 is running with PID : %d\n", getpid());
        printf("Child 2 says : PID of parent is : %d\n", getppid());
    }
    

    Ret3 = fork();

    if(Ret3 == 0)
    {
        
        printf("Child 3 is running with PID : %d\n", getpid());
        printf("Child 3 says : PID of parent is : %d\n", getppid());
    }

    return 0;
}