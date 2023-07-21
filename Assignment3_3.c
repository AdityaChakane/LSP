#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/dir.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char SourceDir[50];
    char DestDir[50];
    char oldname[50];
    char newname[50];

    printf("Enter the name of directory from which you want to move files\n");
    scanf("%s", SourceDir);

    dp = opendir(SourceDir);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    printf("Enter the name of directory in which you want to move files\n");
    scanf("%s", DestDir);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(oldname, "%s/%s", SourceDir, entry->d_name);
        sprintf(newname, "%s/%s", DestDir, entry->d_name);

        rename(oldname, newname);
    }

    closedir(dp);

    return 0;
}