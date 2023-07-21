#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[1024] = {'\0'};
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

    ret = read(fd, Buffer, 15);

    if(ret == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    printf("Data from file is : %s\n", Buffer);

    close(fd);

    return 0;
}