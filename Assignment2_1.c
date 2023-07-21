#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[BLOCKSIZE] = {'\0'};
    char Fname[20];
    int ret = 0;

    printf("Enter the name of file that you want to read\n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDONLY);
    
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,ret);
    }

    close(fd);

    return 0;
}