#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, Ret = 0;
    char fName1[20], fName2[20];
    struct stat obj1, obj2;
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];

    printf("Enter names of files that you want to compare\n");
    scanf("%s %s", fName1, fName2);

    fd1 = open(fName1, O_RDONLY);
    fd2 = open(fName2, O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1, &obj1);
    fstat(fd2, &obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are different\n");
        return -1;
    }

    while((Ret = read(fd1, Buffer1, sizeof(Buffer1))) != 0)
    {
        Ret = read(fd2, Buffer2, sizeof(Buffer2));
        if(memcmp(Buffer1, Buffer2, Ret) != 0)
        {
            break;
        }
    }

    if(Ret == 0)
    {
        printf("Both files are identical\n");
    }
    else
    {
        printf("Both file are different\n");
    }

    close(fd1);
    close(fd2);

    return 0;
}