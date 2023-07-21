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
    char dName[20];
    char fName[20];

    printf("Enter the name of directory\n");
    scanf("%s", dName);

    dp = opendir(dName);

    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    printf("Enter the name of file that you want to check in directory\n");
    scanf("%s", fName);

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(fName, entry->d_name)) == 0)
        {
            printf("File is present in directory\n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("There is no such file\n");
    }

    closedir(dp);

    return 0;
}