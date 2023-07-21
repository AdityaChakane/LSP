#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    char Fname[20];
    
    printf("Enter the file name to access information\n");
    scanf("%s", Fname);

    stat(Fname, &sobj);

    printf("File name : %s\n", Fname);
    printf("File size is : %d\n", sobj.st_size);
    printf("Number of links : %d\n", sobj.st_nlink);
    printf("Inode number : %d\n", sobj.st_ino);
    printf("Number of blocks : %d\n", sobj.st_blocks);


    return 0;
}