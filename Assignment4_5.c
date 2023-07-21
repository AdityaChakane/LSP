#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0,ret = 0;
    char Arr[20];
    char fName[20];
    char Pos[4];

    printf("Enter the file name\n");
    scanf("%s", fName);

    fd = open(fName,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Enter the position from where you want to read data\n");
    scanf("%s", Pos);

    lseek(fd,atoi(Pos),0);

    ret = read(fd,Arr,20);

    printf("Data from file is \n");
    write(1,Arr,ret);

    close(fd);
    return 0;
}