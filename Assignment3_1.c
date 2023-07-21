#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    char Fname1[20];
    char Fname2[20];
    char Buffer[BLOCKSIZE] = {'\0'};
    int ret = 0;

    printf("Enter the file name from which you want to copy data\n");
    scanf("%s", Fname1);

    fdSource = open(Fname1, O_RDONLY);

    if(fdSource == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Enter the file name that you want to create copy data in it\n");
    scanf("%s", Fname2);

    fdDest = creat(Fname2, 0777);

    while((ret = read(fdSource, Buffer, sizeof(Buffer))) != 0)
    {
        write(fdDest, Buffer, ret);
    }

    close(fdSource);
    close(fdDest);

    return 0;
}