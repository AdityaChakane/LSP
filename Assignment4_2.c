#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/dir.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char dName[20];
    int dir = 0;

    printf("Enter the name which you want to give to newly created directory\n");
    scanf("%s", dName);

    dir = mkdir(dName, 0777);

    if(dir == -1)
    {
        printf("Unable to create directory\n");
        return -1;
    }
    else
    {
        printf("Directory created successfully with name : %s\n", dName);
    }


    return 0;
}