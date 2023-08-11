#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int Ret = 0;
    int cpid = 0;
    int Exit_Status = 0;

    Ret = fork();

    printf("Child Running\n");

    if(Ret == 0)
    {
        execl("./GrandChildProcess", "NULL", NULL);
    }
    else
    {
        printf("Parent process\n");
        printf("Parent process is running with PID : %d\n", getpid());
        cpid = wait(&Exit_Status);
        printf("Child process terminated having PID %d with exit status %d\n", cpid, Exit_Status);
    }


    return 0;
}