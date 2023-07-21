#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char Dname[20];
    char name[30];
    char namecopy[30] = {'\0'};
    int iMax = 0;

    printf("Enter the name of directory\n");
    scanf("%s", Dname);

    dp = opendir(Dname);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name, "%s/%s", Dname, entry->d_name);
        stat(name, &sobj);
        if(iMax < sobj.st_size)
        {
            iMax = sobj.st_size;
            strcpy(namecopy, name);
        }
    }

    printf("Name of largest file : %s with size %d bytes \n", namecopy, iMax);

    closedir(dp);

    return 0;
}