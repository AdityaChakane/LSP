#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int Ret = 0;
    int cpid = 0;
    int Exit_Status = 0;

    Ret = fork();

    printf("Parent running\n");

    if(Ret == 0)
    {
        execl("./ChildProcess", "NULL", NULL);
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