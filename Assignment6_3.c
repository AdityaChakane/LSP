#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char dName[20];
    char fName[20];
    char name[50];
    int fd = 0;

    printf("Enter the name of directory\n");
    scanf("%s", dName);

    dp = opendir(dName);

    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    printf("Enter name for newly created file\n");
    scanf("%s", fName);

    sprintf(name, "%s/%s", dName, fName);
    
    fd = creat(name, 0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    printf("File is successfully created with name : %s\n", fName);

    closedir(dp);

    return 0;
}