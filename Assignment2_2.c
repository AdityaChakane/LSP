#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    char data[BLOCKSIZE] = {'\0'};
    char Fname[20];

    printf("Enter the file name that you want to write data in it\n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Enter the data that you want to write in the file\n");
    scanf("%s", data);

    write(fd, data, sizeof(data));

    return 0;
}