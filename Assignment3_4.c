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
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char dName[20];
    char name[50];

    printf("Enter the name of directory\n");
    scanf("%s", dName);

    dp = opendir(dName);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }


    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name, "%s/%s", dName, entry->d_name);
        stat(name, &sobj);
        if((sobj.st_size) == 0)
        {
            remove(name);
        }
    }

    closedir(dp);

    return 0;
}