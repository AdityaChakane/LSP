#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char namecopy[30] = {'\0'};
    int iMax = 0;
    struct FileInfo fobj;

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            printf("File Name : %s\t File Size : %d\n",entry->d_name, sobj.sts);
        }
    }

    closedir(dp);
    
    return 0;
}