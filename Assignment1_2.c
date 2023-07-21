#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char Fname[20];
    int fd = 0;
    char cMode[10];
    int iMode = 0;

    printf("Enter the file name and mode in which you want to open file : \n");
    scanf("%s %s", Fname, cMode);

    if(strcmp(cMode, "Read") == 0)
    {
        iMode = O_RDONLY;
    }
    else if(strcmp(cMode, "Write") == 0)
    {
        iMode = O_WRONLY;
    }
    else
    {
        iMode = O_RDONLY;
    }

    fd = open(Fname, iMode);

    if(fd == -1)
    {
        printf("Unable to open file \n");
        return -1;
    }
    else
    {
        printf("File is successfully opened with FD : %d \n", fd);
    }

    return 0;
}